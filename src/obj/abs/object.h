#ifndef OBJECT_H  // Include guard to prevent multiple inclusions of this header file.
#define OBJECT_H  // Define the macro `OBJECT_H` to ensure the file is included only once.

#include <SFML/Graphics.hpp>          // Include SFML graphics library for rendering shapes and handling windows.
#include "enum/Enum.h"                // Include the `Planets` enum class for gravitational settings.
#include "enum/gravity_constants.h"   // Include constants for gravitational acceleration values.
#include <vector>                     // Include STL vector for managing lists of objects.
#include <memory>                     // Include smart pointers (e.g., `std::unique_ptr`) for memory management.

class Object {
public:
    // Constructor: Initializes an object with default velocity (0, 0) and acceleration (0, 9.8).
    // The default acceleration corresponds to Earth's gravity.
    Object(float angle = 0.0f) : velocity({0.0f, 0.0f}), acceleration({0.0f, 9.8f}) {}

    ~Object() = default;  // Default destructor for cleaning up resources.

    // Static vector to store pointers to static objects (e.g., immovable obstacles).
    static std::vector<sf::Shape*> staticObjects;

    // Public methods:
    void setInitialAngle(float angle);  // Set the initial angle of the object (e.g., for projectile motion).
    void update(float deltaTime);       // Update the object's state based on physics and elapsed time.
    void draw(sf::RenderWindow& window);  // Draw the object on the SFML render window.
    void handleBoundaryCollision(const sf::RenderWindow& window);  // Handle collisions with window boundaries.
    void setGravity(Planets planet);  // Set the gravitational force based on a celestial body (e.g., Earth, Mars).
    void setMass(float mass);         // Set the mass of the object (used in physics calculations).
    float getMass();                  // Get the mass of the object.

    // Static methods for collision handling:
    static void resolveCollision(Object& obj1, Object& obj2);  // Resolve collisions between two objects.
    static bool checkCollision(const Object& obj1, const Object& obj2);  // Check if two objects are colliding.

    // Getter for the bounding box of the object (used for collision detection and sorting).
    sf::FloatRect getBounds() const {
        return sh ? sh->getGlobalBounds() : sf::FloatRect();  // Return the global bounds of the shape or an empty rectangle if no shape exists.
    }

protected:
    std::unique_ptr<sf::Shape> sh;  // Unique pointer to the SFML shape representing the object (e.g., circle, square).
    sf::Vector2f velocity;          // Velocity vector (x, y) of the object.
    sf::Vector2f acceleration;      // Acceleration vector (x, y) of the object.

private:
    float mass = 1.0f;  // Mass of the object, initialized to 1.0 by default.

    // Private static method to create a static copy of an SFML shape (used for static objects).
    static sf::Shape* createStaticCopy(const sf::Shape& original);

    // Template method for creating a static copy of a specific type of SFML shape.
    template <typename T>
    static sf::Shape* createStaticCopyImpl(const T& original);
};

#endif // OBJECT_H  // End of the include guard.