#include "object.h"  // Include the header file for the Object class.
#include <cmath>     // Include the cmath library for mathematical functions like `std::abs`, `std::cos`, and `std::sin`.

// Static field definition: Initialize the static vector to store static objects.
std::vector<sf::Shape*> Object::staticObjects;

// Update the object's state based on physics calculations and elapsed time (deltaTime).
void Object::update(float deltaTime) { 
    velocity += acceleration * deltaTime / mass;  // Update velocity using acceleration and mass.
    if (sh) {
        sh->move(velocity * deltaTime);  // Move the shape based on the updated velocity.
    }
}

// Draw the object on the SFML render window.
void Object::draw(sf::RenderWindow& window) {
    if (sh) {
        window.draw(*sh);  // Render the shape if it exists.
    }
}

// Handle collisions with the boundaries of the window.
void Object::handleBoundaryCollision(const sf::RenderWindow& window) {
    if (!sh) return;  // Exit early if the object has no shape.

    auto bounds = sh->getGlobalBounds();  // Get the bounding box of the shape.
    auto windowSize = window.getSize();   // Get the size of the render window.

    // Check collision with the left boundary.
    if (bounds.left <= 0) {
        velocity.x = std::abs(velocity.x);  // Reverse horizontal velocity to bounce right.
        sh->setPosition(0, bounds.top);     // Reposition the shape to avoid overlapping the boundary.
    }

    // Check collision with the right boundary.
    if (bounds.left + bounds.width >= windowSize.x) {
        velocity.x = -std::abs(velocity.x);  // Reverse horizontal velocity to bounce left.
        sh->setPosition(windowSize.x - bounds.width, bounds.top);  // Reposition the shape.
    }

    // Check collision with the top boundary.
    if (bounds.top <= 0) {
        velocity.y = std::abs(velocity.y);  // Reverse vertical velocity to bounce downward.
        sh->setPosition(bounds.left, 0);    // Reposition the shape.
    }

    // Check collision with the bottom boundary.
    if (bounds.top + bounds.height >= windowSize.y) {
        velocity.y = -std::abs(velocity.y);  // Reverse vertical velocity to bounce upward.
        sh->setPosition(bounds.left, windowSize.y - bounds.height);  // Reposition the shape.
    }
}

// Set the gravitational force based on the selected celestial body.
void Object::setGravity(Planets planet) {
    float gravity = 0.0f;
    switch (planet) {
        case Planets::Earth: 
            gravity = GRAVITY_EARTH;  // Earth's gravity (~9.8 m/s²).
            break;
        case Planets::Jupiter: 
            gravity = GRAVITY_JUPITER;  // Jupiter's gravity (~24.8 m/s²).
            break;
        case Planets::Moon: 
            gravity = GRAVITY_MOON;  // Moon's gravity (~1.6 m/s²).
            break;
        case Planets::Mars: 
            gravity = GRAVITY_MARS;  // Mars' gravity (~3.7 m/s²).
            break;
        case Planets::Sun: 
            gravity = GRAVITY_SUN;  // Sun's gravity (~274.8 m/s²).
            break;
        default: 
            gravity = GRAVITY_EARTH;  // Default to Earth's gravity if an invalid planet is provided.
            break;
    }
    this->acceleration.y = gravity * mass;  // Update the vertical acceleration based on gravity and mass.
}

// Set the mass of the object.
void Object::setMass(float mass) {
    this->mass = mass;  // Assign the new mass value.
}

// Get the mass of the object.
float Object::getMass() {
    return this->mass;  // Return the current mass.
}

// Resolve a collision between two objects.
void Object::resolveCollision(Object& obj1, Object& obj2) {
    float m1 = obj1.getMass();  // Mass of the first object.
    float m2 = obj2.getMass();  // Mass of the second object.

    sf::Vector2f v1 = obj1.velocity;  // Velocity of the first object.
    sf::Vector2f v2 = obj2.velocity;  // Velocity of the second object.

    // Calculate new velocities after the collision using conservation of momentum and energy.
    obj1.velocity = ((m1 - m2) * v1 + 2.0f * m2 * v2) / (m1 + m2);
    obj2.velocity = ((m2 - m1) * v2 + 2.0f * m1 * v1) / (m1 + m2);

    // Correct positions to prevent overlapping.
    auto bounds1 = obj1.getBounds();  // Bounding box of the first object.
    auto bounds2 = obj2.getBounds();  // Bounding box of the second object.

    sf::Vector2f overlap = {
        std::min(bounds1.left + bounds1.width - bounds2.left, bounds2.left + bounds2.width - bounds1.left),
        std::min(bounds1.top + bounds1.height - bounds2.top, bounds2.top + bounds2.height - bounds1.top)
    };

    // Resolve overlap along the axis with the smallest penetration.
    if (overlap.x < overlap.y) {
        obj1.sh->move(-overlap.x, 0);  // Move the first object horizontally.
        obj2.sh->move(overlap.x, 0);   // Move the second object horizontally.
    } else {
        obj1.sh->move(0, -overlap.y);  // Move the first object vertically.
        obj2.sh->move(0, overlap.y);   // Move the second object vertically.
    }

    // Create static copies of the colliding objects to simulate "debris."
    staticObjects.push_back(createStaticCopy(*obj1.sh));  // Add a static copy of the first object.
    staticObjects.push_back(createStaticCopy(*obj2.sh));  // Add a static copy of the second object.

    // Reduce the size of the shapes by 5% to simulate deformation.
    obj1.sh->setScale(obj1.sh->getScale() * 0.95f);
    obj2.sh->setScale(obj2.sh->getScale() * 0.95f);
}

// Check if two objects are colliding by testing if their bounding boxes intersect.
bool Object::checkCollision(const Object& obj1, const Object& obj2) {
    return obj1.getBounds().intersects(obj2.getBounds());  // Return true if the bounding boxes overlap.
}

// Set the initial angle of the object, which determines its initial velocity direction.
void Object::setInitialAngle(float angle) { 
    const float INITIAL_SPEED = 100.0f;  // Fixed initial speed for all objects.
    float radians = angle * 3.14159265358979323846f / 180.0f;  // Convert degrees to radians.
    velocity.x = INITIAL_SPEED * std::cos(radians);  // Horizontal velocity component.
    velocity.y = INITIAL_SPEED * std::sin(radians);  // Vertical velocity component.
}

// Template function to create a static copy of a specific type of SFML shape.
template <typename T>
sf::Shape* Object::createStaticCopyImpl(const T& original) {
    auto* copy = new T(original);  // Create a new instance of the same shape type.
    copy->setPosition(original.getPosition());  // Copy the position of the original shape.

    sf::Color color = original.getFillColor();  // Get the fill color of the original shape.
    color.a = 64;  // Reduce the opacity to make the static copy semi-transparent.
    copy->setFillColor(color);  // Apply the modified color to the copy.

    return copy;  // Return the pointer to the static copy.
}

// Create a static copy of an SFML shape by dynamically determining its type.
sf::Shape* Object::createStaticCopy(const sf::Shape& original) {
    // Use dynamic_cast to determine the type of the shape and call the appropriate template function.
    if (auto circle = dynamic_cast<const sf::CircleShape*>(&original)) {
        return createStaticCopyImpl(*circle);  // Handle CircleShape.
    } else if (auto rect = dynamic_cast<const sf::RectangleShape*>(&original)) {
        return createStaticCopyImpl(*rect);  // Handle RectangleShape.
    } else if (auto convex = dynamic_cast<const sf::ConvexShape*>(&original)) {
        return createStaticCopyImpl(*convex);  // Handle ConvexShape.
    }
    return nullptr;  // Return null if the shape type is unsupported.
}
