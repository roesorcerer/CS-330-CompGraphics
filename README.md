# Week 3 Graphics and Visualization Project

This GitHub repository contains the code for the 3D environment project completed during Week 3 of my Graphics and Visualization class. In this project, I followed the tutorial provided in the [OpenGL Tutorials](https://github.com/VictorGordan/opengl-tutorials) repository to set up a 3D environment using OpenGL.

## Project Overview

The project consists of a 3D environment rendered using OpenGL. It includes a square with textured surfaces and a pyramid-like structure on top. The square has changing colors, and the pyramid can be rotated.

## Dependencies

Before running the code, make sure you have the following dependencies installed:

- [GLFW](https://www.glfw.org/): GLFW is used for window management.
- [GLAD](https://glad.dav1d.de/): GLAD is used to load OpenGL functions.
- [stb_image](https://github.com/nothings/stb): The stb_image library is used for loading textures.
- [glm](https://github.com/g-truc/glm): The glm library is used for mathematics and transformations.
- [Texture.h, shaderClass.h, VAO.h, VBO.h, EBO.h](#code-structure): These custom header files are used for organizing code.

## Code Structure

The project is organized into several components:

- `Texture.h`: Handles loading and managing textures.
- `shaderClass.h`: Manages shader programs.
- `VAO.h`: Defines and manages Vertex Array Objects.
- `VBO.h`: Defines and manages Vertex Buffer Objects.
- `EBO.h`: Defines and manages Element Buffer Objects.
- `default.vert` and `default.frag`: Vertex and fragment shaders used for rendering.

## Running the Code

To run the code, follow these steps:

1. Clone or download this repository to your local machine.

2. Ensure you have the required dependencies installed on your system (GLFW, GLAD, stb_image, glm).

3. Compile and run the code using your preferred C++ compiler. Make sure to include the necessary libraries and header files in your build process.

4. The application window should open, displaying the 3D environment. You can interact with the environment by rotating the pyramid structure.

## Notes

- The project uses OpenGL 3.3 with the CORE profile.

- Textures are loaded and applied to the surfaces.

- The project uses matrices for transformations, including model, view, and projection matrices.

- The depth buffer is enabled for a more realistic rendering.

- The code includes error checking for various stages, such as window creation and shader compilation.

- The code also includes a simple timer for the rotation of the pyramid.

Feel free to explore and modify the code to further enhance your understanding of 3D graphics and OpenGL. If you have any questions or encounter any issues, please feel free to reach out.

Happy coding!

---

*This ReadMe file was created by [Rowan Stratton].*
