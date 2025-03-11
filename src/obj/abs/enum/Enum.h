#ifndef PLANETS_H  // Include guard to prevent multiple inclusions of this header file.
#define PLANETS_H  // Define the macro `PLANETS_H` to ensure the file is included only once.

// Define an enumeration class named `Planets` to represent different celestial bodies.
// This allows us to use strongly-typed constants for planets, improving code readability and safety.
enum class Planets {
    Earth,   // Represents Earth, typically associated with standard gravity (9.81 m/s²).
    Moon,    // Represents the Moon, which has weaker gravity (~1.62 m/s²).
    Mars,    // Represents Mars, known for its lower gravity (~3.721 m/s²).
    Jupiter, // Represents Jupiter, which has much stronger gravity (~24.79 m/s²).
    Sun      // Represents the Sun, with extremely strong gravity (~274 m/s²).
};

#endif // PLANETS_H  // End of the include guard.