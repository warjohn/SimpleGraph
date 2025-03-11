#ifndef GRAVITY_CONSTANTS_H  // Include guard to prevent multiple inclusions of this header file.
#define GRAVITY_CONSTANTS_H  // Define the macro `GRAVITY_CONSTANTS_H` to ensure the file is included only once.

// Define constants for gravitational acceleration on different celestial bodies.
// These values are expressed in meters per second squared (m/s²) and are used to simulate gravity in the program.

constexpr float GRAVITY_EARTH = 9.8f;    // Gravitational acceleration on Earth (~9.8 m/s²).
constexpr float GRAVITY_MOON = 1.6f;     // Gravitational acceleration on the Moon (~1.6 m/s²).
constexpr float GRAVITY_MARS = 3.7f;     // Gravitational acceleration on Mars (~3.7 m/s²).
constexpr float GRAVITY_JUPITER = 24.8f; // Gravitational acceleration on Jupiter (~24.8 m/s²).
constexpr float GRAVITY_SUN = 274.8f;    // Gravitational acceleration on the Sun (~274.8 m/s²).

#endif // GRAVITY_CONSTANTS_H  // End of the include guard.