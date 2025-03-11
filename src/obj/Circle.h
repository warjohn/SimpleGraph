#ifndef CIRCLE_H  // Include guard to prevent multiple inclusions of this header file.
#define CIRCLE_H  // Define the macro `CIRCLE_H` to ensure the file is included only once.

#include "../stcmIncludes.h"  // Include a custom header file that likely contains necessary dependencies (e.g., SFML, constants, etc.).
#include "abs/object.h"       // Include the base `Object` class header file.

// Definition of the `Circle` class, which inherits from the `Object` class.
class Circle : public Object {

public:
    // Constructor: Initializes a circle with a given radius, position, and color.
    Circle(float radius, sf::Vector2f position, sf::Color color) {
        // Create an SFML `CircleShape` object using a unique pointer for memory management.
        sh = std::make_unique<sf::CircleShape>(radius);  // Set the radius of the circle.
        sh->setPosition(position);  // Set the position of the circle on the screen.
        sh->setFillColor(color);    // Set the fill color of the circle.
    }
};

#endif // CIRCLE_H  // End of the include guard.