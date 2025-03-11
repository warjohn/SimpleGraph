# Physics Engine Simulation 
## Overview 

This project is a simple physics engine simulation built using SFML  for rendering and OpenCV  for video recording. It simulates basic physics concepts such as gravity, collisions, and motion for various shapes (circles, squares, and triangles). The program allows users to set gravitational forces based on different celestial bodies (e.g., Earth, Mars, Sun) and records the simulation as a video file. 

## Features 

    Physics Simulation : 
        Objects are affected by gravity based on the selected celestial body.
        Objects can collide with each other and the boundaries of the window.
        Collision resolution uses conservation of momentum and energy.
         

    Dynamic and Static Objects : 
        Dynamic objects (circles, squares, triangles) move and interact with each other.
        Static objects (immovable debris) are created after collisions to simulate remnants.
         

    Customizable Gravity : 
        Gravitational forces can be set for Earth, Moon, Mars, Jupiter, or the Sun.
         

    Video Recording : 
        The simulation is recorded in real-time and saved as an .avi video file using OpenCV.
         

    Object Types : 
        Circle : Represents circular objects.
        Square : Represents square objects.
        Triangle : Represents triangular objects.
         

    Initial Conditions : 
        Objects can be initialized with specific positions, sizes, colors, and initial angles for projectile motion.
         
profile
Qwen2.5-Max 4:39 pm
 
Physics Engine Simulation 
Overview 

This project is a simple physics engine simulation built using SFML  for rendering and OpenCV  for video recording. It simulates basic physics concepts such as gravity, collisions, and motion for various shapes (circles, squares, and triangles). The program allows users to set gravitational forces based on different celestial bodies (e.g., Earth, Mars, Sun) and records the simulation as a video file. 
Features 

    Physics Simulation : 
        Objects are affected by gravity based on the selected celestial body.
        Objects can collide with each other and the boundaries of the window.
        Collision resolution uses conservation of momentum and energy.
         

    Dynamic and Static Objects : 
        Dynamic objects (circles, squares, triangles) move and interact with each other.
        Static objects (immovable debris) are created after collisions to simulate remnants.
         

    Customizable Gravity : 
        Gravitational forces can be set for Earth, Moon, Mars, Jupiter, or the Sun.
         

    Video Recording : 
        The simulation is recorded in real-time and saved as an .avi video file using OpenCV.
         

    Object Types : 
        Circle : Represents circular objects.
        Square : Represents square objects.
        Triangle : Represents triangular objects.
         

    Initial Conditions : 
        Objects can be initialized with specific positions, sizes, colors, and initial angles for projectile motion.
         
     

## Dependencies 

To compile and run this project, you need the following libraries installed: 

    SFML : 
        Used for rendering shapes, handling windows, and managing graphical objects.
        Website: https://www.sfml-dev.org/ 
         

    OpenCV : 
        Used for capturing frames and recording the simulation as a video file.
        Website: https://opencv.org/ 
         

    C++ Compiler : 
        A modern C++ compiler that supports C++17 or later (e.g., GCC, Clang, MSVC).
         

    CMake  (Optional): 
        If the project uses CMake for building, ensure it is installed.
         
## Installation and Setup 
### Step 1: Install Dependencies 

    SFML : 
        On Linux: sudo apt install libsfml-dev
        On Windows: Download the precompiled binaries from the SFML website and link them to your project.
         

    OpenCV : 
        On Linux: sudo apt install libopencv-dev
        On Windows: Download the precompiled binaries from the OpenCV website and link them to your project.
         
     

### Step 2: Clone the Repository 

### Step 3: Build the Project
bash```
git clone https://github.com/your-repo/physics-engine.git
cd physics-engine
```

#### Using a Makefile or CMake: 

    If the project includes a Makefile or CMakeLists.txt, use the following commands:

bash```
mkdir build && cd build
cmake ..
make
```
### Usage 

    Window Controls : 
        Close the window by clicking the close button or pressing the Esc key.
        Resize the window to dynamically adjust object positions.
         

    Simulation Settings : 
        Modify the gravitational force by changing the setGravity calls in the main.cpp file.
        Adjust object properties (size, position, color, mass, etc.) in the main.cpp file.
         

    Output : 
        The simulation is recorded as an .avi video file named output.avi in the working directory.
         
### Customization 

    Adding New Shapes : 
        Create a new class (e.g., Pentagon) that inherits from the Object class.
        Implement the constructor and any additional functionality in the corresponding .cpp file.
         

    Changing Gravity : 
        Modify the Planets enum and gravity_constants.h to add new celestial bodies or adjust existing values.
         

    Adjusting Simulation Parameters : 
        Change the initial velocity, mass, size, or position of objects in the main.cpp file.
         
### Contributing 

Contributions are welcome! If you'd like to contribute, please follow these steps: 

    Fork the repository.
    Create a new branch for your feature or bug fix.
    Submit a pull request with a detailed description of your changes.
     
### Acknowledgments 

    SFML Team : For providing an excellent library for graphics and window management.
    OpenCV Team : For enabling video recording and image processing capabilities.
    Physics Concepts : Inspired by classical mechanics and collision dynamics.
     