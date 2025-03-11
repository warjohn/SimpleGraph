#ifndef TRIANGLE_H  // Include guard to prevent multiple inclusions of this header file.
#define TRIANGLE_H  // Define the macro `TRIANGLE_H` to ensure the file is included only once.

#include "../stcmIncludes.h"  // Include a custom header file that likely contains necessary dependencies (e.g., SFML, constants, etc.).
#include "abs/object.h"       // Include the base `Object` class header file.

// Definition of the `Triangle` class, which inherits from the `Object` class.
class Triangle : public Object {

public:
    // Constructor: Initializes a triangle with a given size, position, and color.
    Triangle(float size, sf::Vector2f position, sf::Color color) {
        // Create an SFML `ConvexShape` object with 3 points (a triangle) using a unique pointer for memory management.
        sh = std::make_unique<sf::ConvexShape>(3);  // Initialize the convex shape with 3 vertices.

        // Cast the shape to `sf::ConvexShape` to access its specific methods.
        auto& convex = static_cast<sf::ConvexShape&>(*sh);

        // Define the three vertices of the triangle:
        convex.setPoint(0, {0, 0});               // Top-left corner.
        convex.setPoint(1, {size, 0});            // Top-right corner.
        convex.setPoint(2, {size / 2, size});     // Bottom-center point.

        // Set the position and color of the triangle.
        sh->setPosition(position);  // Set the position of the triangle on the screen.
        sh->setFillColor(color);    // Set the fill color of the triangle.
    }
};

#endif // TRIANGLE_H  // End of the include guard.