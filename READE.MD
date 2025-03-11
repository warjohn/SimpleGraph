# Physics Engine Simulation

## Overview

This project is a simple physics engine simulation built using **SFML** for rendering and **OpenCV** for video recording. It simulates basic physics concepts such as gravity, collisions, and motion for various shapes (circles, squares, and triangles). The program allows users to set gravitational forces based on different celestial bodies (e.g., Earth, Mars, Sun) and records the simulation as a video file.

---

## Features

- **Physics Simulation**:
  - Objects are affected by gravity based on the selected celestial body.
  - Objects can collide with each other and the boundaries of the window.
  - Collision resolution uses conservation of momentum and energy.

- **Dynamic and Static Objects**:
  - Dynamic objects (circles, squares, triangles) move and interact with each other.
  - Static objects (immovable debris) are created after collisions to simulate remnants.

- **Customizable Gravity**:
  - Gravitational forces can be set for Earth, Moon, Mars, Jupiter, or the Sun.

- **Video Recording**:
  - The simulation is recorded in real-time and saved as an `.avi` video file using OpenCV.

- **Object Types**:
  - **Circle**: Represents circular objects.
  - **Square**: Represents square objects.
  - **Triangle**: Represents triangular objects.

- **Initial Conditions**:
  - Objects can be initialized with specific positions, sizes, colors, and initial angles for projectile motion.

---

## Dependencies

To compile and run this project, you need the following libraries installed:

- **SFML**:
  - Used for rendering shapes, handling windows, and managing graphical objects.
  - Website: [SFML](https://www.sfml-dev.org/)

- **OpenCV**:
  - Used for capturing frames and recording the simulation as a video file.
  - Website: [OpenCV](https://opencv.org/)

- **C++ Compiler**:
  - A modern C++ compiler that supports C++17 or later (e.g., GCC, Clang, MSVC).

- **CMake** (Optional):
  - If the project uses CMake for building, ensure it is installed.

---

## Installation and Setup

### Step 1: Install Dependencies

- **SFML**:
  - On Linux: `sudo apt install libsfml-dev`
  - On Windows: Download the precompiled binaries from the [SFML website](https://www.sfml-dev.org/) and link them to your project.

- **OpenCV**:
  - On Linux: `sudo apt install libopencv-dev`
  - On Windows: Download the precompiled binaries from the [OpenCV website](https://opencv.org/) and link them to your project.

### Step 2: Clone the Repository

```bash
git clone https://github.com/your-repo/physics-engine.git
cd physics-engine```

