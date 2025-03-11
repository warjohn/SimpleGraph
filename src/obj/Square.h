#ifndef SQUARE_H  // Include guard to prevent multiple inclusions of this header file.
#define SQUARE_H  // Define the macro `SQUARE_H` to ensure the file is included only once.

#include "../stcmIncludes.h"  // Include a custom header file that likely contains necessary dependencies (e.g., SFML, constants, etc.).
#include "abs/object.h"       // Include the base `Object` class header file.

// Definition of the `Square` class, which inherits from the `Object` class.
class Square : public Object {

public:
    // Constructor: Initializes a square with a given size, position, and color.
    Square(float size, sf::Vector2f position, sf::Color color) {
        // Create an SFML `RectangleShape` object using a unique pointer for memory management.
        sh = std::make_unique<sf::RectangleShape>(sf::Vector2f{size, size});  // Set the size of the square (width = height = size).
        sh->setPosition(position);  // Set the position of the square on the screen.
        sh->setFillColor(color);    // Set the fill color of the square.
    }
};

#endif // SQUARE_H  // End of the include guard.