//Simple 2d triangle - no indecies just verticies to create the triangle 

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{
	//Initializa GLFW
	glfwInit();

	//GLFW version that is being used, I am using 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//GLFW CORE profiles
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

	// Main GLFW window object - 800 by 800 pixels 
	GLFWwindow* window = glfwCreateWindow(800, 800, "Rowan Stratton Project CS 330", NULL, NULL);
	//error checking 
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	//Introduce the window 
	glfwMakeContextCurrent(window);

	//glad loader
	gladLoadGL();

	//Viewport of the OpenGL window I am going with 800 by 800 pixels 
	glViewport(0, 0, 800, 800);

	//vertex shader object
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);//vertex shader source and object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);//complie vertex shader

	//fragment shader object
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);//fragment shader source and ogject
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);//compile fragment shader

	//This creates a shaderProgram object
	GLuint shaderProgram = glCreateProgram();
	//attaches both vertex and fragment shader objects to shader program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	//Link it all together
	glLinkProgram(shaderProgram);

	//delete the shader objects that are not in use anymore
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//Vartex Array Object and the Vertex Buffer Object objects
	GLuint VAO, VBO;

	//VAO and VBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// VAO as the current vertex array
	glBindVertexArray(VAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER, which is the type of buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//store buffer

	// how to read VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Bind both the VBO and VAO to 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);//navy blue
	//Clean the bakc buffer and get a new color on it
	glClear(GL_COLOR_BUFFER_BIT);
	//Swap the bakc and front buffers 
	glfwSwapBuffers(window);

	//window stays open until close box
	while (!glfwWindowShouldClose(window))
	{
		//color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);//navy blue
		//Clean the bakc buffer and get a new color on it
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		//all GLFW events
		glfwPollEvents();
	}

	//deleting the objects
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	//delete the window before ending the program
	glfwDestroyWindow(window);
	//GLFW terminate 
	glfwTerminate();
	return 0;
}