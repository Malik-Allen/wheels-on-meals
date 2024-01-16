// MIT License, Copyright (c) 2024 Malik Allen

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class IWindowHandler;

class IInputHandler
{
public:
    IInputHandler() = default;
    virtual ~IInputHandler() = default;
    
    virtual bool Initialize(IWindowHandler* windowHandler) = 0;
    virtual void Update() = 0;
    virtual bool IsKeyDown( const int keyID ) const = 0;
    virtual bool IsGamepadButtonDown( const int gamepadID, const int buttonID ) const = 0;
};

#endif
