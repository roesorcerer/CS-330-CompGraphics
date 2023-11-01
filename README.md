# Application ReadMe

## Introduction

This ReadMe file provides an overview of the code in the `Application` class, which appears to be a part of a C++ application. The code appears to be related to window creation and management using the GLFW and OpenGL libraries.

## Code Description

### Application Class

The `Application` class contains the following main functions and members:

- **Constructor**: `Application(std::string WindowTitle, int width, int height)`: The constructor initializes the application with a window title, width, and height.

- **Run**: `void Application::Run()`: The `Run` method starts the main application loop, which continues until the user closes the window. Inside the loop, it swaps buffers and polls for events.

- **openWindow**: `bool Application::openWindow()`: The `openWindow` method initializes GLFW, creates a window, and sets up OpenGL context. It also handles error checking for window creation and OpenGL initialization.

## Usage

To use the `Application` class in your project, you can follow these steps:

1. Include the necessary headers:
   
   ```cpp
   #include "application.h"
   #include <iostream>
2. Call the `Run` method to start the application loop:
   
   `Application app("My OpenGL App", 800, 600);`
   
3. Customize the code inside the `Run` method to implement your application's logic.
   
   ```cpp
   #include "application.h"
   #include <iostream>
   
## Dependencies


This code relies on the following dependencies:

GLFW: Used for window management.
OpenGL: Used for graphics rendering. 

Ensure that you have these libraries properly installed and configured in your development environment before using this code.
