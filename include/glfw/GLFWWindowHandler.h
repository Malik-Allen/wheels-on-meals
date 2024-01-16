// MIT License, Copyright (c) 2024 Malik Allen

#ifndef GLFWWINDOWHANDLER_H
#define GLFWWINDOWHANDLER_H

#include "../WindowHandler.h"

class GLFWwindow;

class GLFWWindowHandler : public IWindowHandler
{
    friend class GLFWInputHandler;
public:
    GLFWWindowHandler();
    ~GLFWWindowHandler() override = default;
    
    virtual bool InitializeWindow(const int width, const int height, const std::string& name) override;
    virtual bool IsWindowOpen() const override;
    virtual void ProcessEvents() const override;
    virtual void Shutdown() const override;

private:
    GLFWwindow* m_window;
};

#endif