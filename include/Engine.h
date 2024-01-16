// MIT License, Copyright (c) 2019 Malik Allen

#ifndef ENGINE_H
#define ENGINE_H

#include "Singleton.h"

#include <string>

class EngineClock;
class IWindowHandler;
class IInputHandler;
class IApp;

class Engine : public Singleton<Engine>
{
    friend class Singleton;
    
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (Engine&&) = delete;
    
    Engine();
    
    bool m_isRunning;
    std::unique_ptr<EngineClock> m_clock;
    std::shared_ptr<IWindowHandler> m_windowHandler;
    std::shared_ptr<IInputHandler> m_inputHandler;
    std::shared_ptr<IApp> m_app;

    void Update(const float deltaTime);
    
public:
    bool Start(const unsigned int fps, const int width, const int height, const std::string& name);

    bool LoadApp(IApp* app);
    
    void Run();

    bool IsRunning() const { return m_isRunning; }

    void Shutdown();

    const IInputHandler* GetInputHandler() const { return m_inputHandler.get(); }
};

#endif // !ENGINE_H