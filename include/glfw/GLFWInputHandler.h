// MIT License, Copyright (c) 2024 Malik Allen

#ifndef GLFWINPUTHANDLER_H
#define GLFWINPUTHANDLER_H

#include "../InputHandler.h"

class GLFWWindowHandler;

class GLFWInputHandler : public IInputHandler
{
public:
    GLFWInputHandler();
    ~GLFWInputHandler() override = default;

    virtual bool Initialize(IWindowHandler* windowHandler) override;
    virtual void Update() override;
    virtual bool IsKeyDown( const int keyID ) const override;
    virtual bool IsGamepadButtonDown( const int gamepadID, const int buttonID ) const override;
    
private:
    const GLFWWindowHandler* m_windowHandler;
};

#endif