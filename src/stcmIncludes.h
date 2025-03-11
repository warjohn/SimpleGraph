#pragma once  // Ensures this file is included only once during compilation, serving as an alternative to traditional include guards.

#include <SFML/Graphics.hpp>  // Include SFML's graphics module for rendering and window management.
#include <iostream>           // Include the standard input-output stream library for debugging or logging purposes.
#include "obj/Circle.h"       // Include the `Circle` class, which represents circular objects in the simulation.
#include "obj/Square.h"       // Include the `Square` class, which represents square objects in the simulation.
#include "obj/Triangle.h"     // Include the `Triangle` class, which represents triangular objects in the simulation.
#include "obj/abs/object.h"   // Include the base `Object` class, which provides shared functionality for all objects.

#include <opencv2/opencv.hpp>  // Include OpenCV for video recording and image processing capabilities.