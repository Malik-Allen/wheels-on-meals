// MIT License, Copyright (c) 2024 Malik Allen

#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H

#include <string>

class IWindowHandler
{
public:
    IWindowHandler() = default;
    virtual ~IWindowHandler() = default;

    virtual bool InitializeWindow(const int width, const int height, const std::string& name) = 0;
    virtual bool IsWindowOpen() const = 0;
    virtual void ProcessEvents() const = 0;
    virtual void Shutdown() const = 0;
};

#endif
