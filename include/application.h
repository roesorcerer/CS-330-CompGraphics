#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application {
public:
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();


private:
	std::string applicationNameP{};
	int widthP{};
	int heightP{};
	GLFWwindow* windowP{ nullptr };

	bool runningP{ false };
};

