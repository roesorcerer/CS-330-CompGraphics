#include "application.h"

#include <iostream>


Application::Application(std::string WindowTitle, int width, int height) : applicationNameP{ WindowTitle }, widthP{ width }, heightP{ height } {

}
void Application::Run() {
    if (!openWindow()) {
        return;
    }

    runningP = true;

    while (runningP) {
        if (glfwWindowShouldClose(windowP)) {
            runningP = false;
            break;
        }

        glfwSwapBuffers(windowP);
        glfwPollEvents();
    }

    glfwTerminate();
}

bool Application::openWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Remove the type declaration GLFWwindow* here
    windowP = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);

    if (!windowP) {
        std::cerr << "Failed to Create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(windowP);
    glfwSetFramebufferSizeCallback(windowP, [](GLFWwindow* window, int width, int height) {
        // Calls whenever the window gets resized
        std::cout << "Window has been resized!" << std::endl;
        glViewport(0, 0, width, height);
        });

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }

    return true;
}

