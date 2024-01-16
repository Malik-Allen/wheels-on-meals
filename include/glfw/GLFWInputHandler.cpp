// MIT License, Copyright (c) 2024 Malik Allen

#include "GLFWInputHandler.h"
#include "GLFWWindowHandler.h"

#include <GLFW/glfw3.h>

GLFWInputHandler::GLFWInputHandler() :
    m_windowHandler(nullptr)
{}

bool GLFWInputHandler::Initialize(IWindowHandler* windowHandler)
{
    m_windowHandler = dynamic_cast<GLFWWindowHandler*>(windowHandler);
    return m_windowHandler != nullptr;
}

void GLFWInputHandler::Update()
{
    glfwPollEvents();
}

bool GLFWInputHandler::IsKeyDown(const int keyID) const
{
    return m_windowHandler != nullptr && glfwGetKey(m_windowHandler->m_window, keyID) == GLFW_PRESS;
}

bool GLFWInputHandler::IsGamepadButtonDown(const int gamepadID, const int buttonID) const
{
    if(glfwJoystickPresent(gamepadID) && glfwJoystickIsGamepad(gamepadID))
    {
        GLFWgamepadstate state;
        if(glfwGetGamepadState(gamepadID, &state))
        {
            return state.buttons[buttonID] == GLFW_PRESS;
        }
    }
    return false;
}
