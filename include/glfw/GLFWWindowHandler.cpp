// MIT License, Copyright (c) 2024 Malik Allen

#include "GLFWWindowHandler.h"

#include <GLFW/glfw3.h>

GLFWWindowHandler::GLFWWindowHandler():
    m_window(nullptr)
{}

bool GLFWWindowHandler::InitializeWindow(const int width, const int height, const std::string& name)
{
    if (!glfwInit()) {
        return false;
    }
    m_window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    return m_window != nullptr;
}

bool GLFWWindowHandler::IsWindowOpen() const
{
    return m_window != nullptr && !glfwWindowShouldClose(m_window);
}

void GLFWWindowHandler::ProcessEvents() const
{
    if (m_window) {
        glfwPollEvents();
        if (glfwWindowShouldClose(m_window)) {
            glfwDestroyWindow(m_window);
            glfwTerminate();
        }
    }
}

void GLFWWindowHandler::Shutdown() const
{
    if(m_window)
    {
        glfwSetWindowShouldClose(m_window, GLFW_TRUE);
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}
