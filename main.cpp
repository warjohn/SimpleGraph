#include "src/stcmIncludes.h"  // Include custom header file that likely contains class definitions and dependencies.

int main() {
    // Create an SFML RenderWindow with a resolution of 800x600 pixels, titled "Physics Engine".
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Engine", sf::Style::Default);

    // Create physics objects: a circle, a square, and a triangle, each with specific properties.
    Circle circle(50.0f, {100, 100}, sf::Color::Red);  // Circle with radius 50, position (100, 100), and red color.
    Square square(100.0f, {300, 100}, sf::Color::Blue);  // Square with side length 100, position (300, 100), and blue color.
    Triangle triangle(100.0f, {500, 100}, sf::Color::Green);  // Triangle with base/height 100, position (500, 100), and green color.

    // Set gravitational forces for each object based on different planets.
    circle.setGravity(Planets::Earth);  // Earth's gravity for the circle.
    square.setGravity(Planets::Mars);  // Mars' gravity for the square.
    triangle.setGravity(Planets::Sun);  // Sun's gravity for the triangle.

    // Set mass for each object (all set to 1.0).
    circle.setMass(1.0f);
    square.setMass(1.0f);
    triangle.setMass(1.0f);

    // Set initial angles for each object (in degrees).
    circle.setInitialAngle(45.0f);  // Circle starts at 45 degrees.
    square.setInitialAngle(90.0f);  // Square starts at 90 degrees.
    triangle.setInitialAngle(0.0f);  // Triangle starts at 0 degrees.

    // Store all objects in a vector for easier management.
    std::vector<Object*> objects = {&circle, &square, &triangle};

    // Create an SFML clock to measure time between frames.
    sf::Clock clock;

    // Initialize OpenCV VideoWriter to record the simulation as a video file.
    cv::VideoWriter videoWriter;
    int frameWidth = window.getSize().x;  // Get window width.
    int frameHeight = window.getSize().y;  // Get window height.
    videoWriter.open("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeight), true);
    if (!videoWriter.isOpened()) {  // Check if the video file was successfully opened.
        std::cerr << "Error: Failed to open file for video recording!" << std::endl;
        return -1;  // Exit the program with an error code.
    }

    // Main game loop.
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {  // Poll for events like closing the window or resizing it.
            if (event.type == sf::Event::Closed)
                window.close();  // Close the window if the close event is triggered.

            if (event.type == sf::Event::Resized) {
                // Update the visible area of the window when resized.
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));

                // Adjust object positions to handle boundary collisions after resizing.
                for (auto obj : objects) {
                    obj->handleBoundaryCollision(window);  // Check and handle collisions with window boundaries.
                }
            }
        }

        // Calculate the time elapsed since the last frame (delta time).
        float deltaTime = clock.restart().asSeconds();

        // Clear the window and update/draw all objects.
        window.clear();
        for (auto obj : objects) {
            obj->update(deltaTime);  // Update the object's state based on physics and delta time.
            obj->handleBoundaryCollision(window);  // Handle boundary collisions for each object.
        }

        // Sort objects by their horizontal position to optimize collision detection.
        std::sort(objects.begin(), objects.end(), [](const Object* a, const Object* b) {
            return a->getBounds().left < b->getBounds().left;
        });

        // Perform collision detection and resolution for nearby objects only.
        for (size_t i = 0; i < objects.size(); ++i) {
            for (size_t j = i + 1; j < objects.size(); ++j) {
                // If the objects are too far apart horizontally, skip further checks.
                if (objects[j]->getBounds().left > objects[i]->getBounds().left + objects[i]->getBounds().width) {
                    break;
                }
                // Check for collisions and resolve them if detected.
                if (Object::checkCollision(*objects[i], *objects[j])) {
                    Object::resolveCollision(*objects[i], *objects[j]);
                }
            }
        }

        // Draw all dynamic objects.
        for (auto obj : objects) {
            obj->draw(window);
        }

        // Draw all static objects stored in the staticObjects list.
        for (auto staticObj : Object::staticObjects) {
            window.draw(*staticObj);
        }

        // Display the updated frame on the screen.
        window.display();

        // Capture the current frame as an image for video recording.
        sf::Texture texture;
        texture.create(window.getSize().x, window.getSize().y);  // Create a texture matching the window size.
        texture.update(window);  // Update the texture with the current window contents.

        // Convert the texture to an SFML image and then to an OpenCV Mat for video writing.
        sf::Image screenshot = texture.copyToImage();
        cv::Mat frame(frameHeight, frameWidth, CV_8UC4, const_cast<uint8_t*>(screenshot.getPixelsPtr()));
        cv::cvtColor(frame, frame, cv::COLOR_RGBA2BGR);  // Convert from RGBA to BGR format for OpenCV compatibility.
        videoWriter.write(frame);  // Write the frame to the video file.
    }

    // Release the video writer resources and exit the program.
    videoWriter.release();
    return 0;
}