cmake_minimum_required(VERSION 3.10.0)
project(Engn VERSION 0.1.0 LANGUAGES C CXX)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(OpenCV REQUIRED)


add_executable(Engn main.cpp 
                    src/stcmIncludes.cpp
                    src/obj/abs/object.cpp)

target_link_libraries(Engn PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(Engn PRIVATE ${OpenCV_LIBS})