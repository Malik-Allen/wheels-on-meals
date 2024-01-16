// MIT License, Copyright (c) 2019 Malik Allen

#include "Engine.h"
#include "EngineClock.h"
#include "App.h"

#include "GLFW/GLFWInputHandler.h"
#include "GLFW/GLFWWindowHandler.h"

Engine::Engine():
    m_isRunning(false),
    m_clock(std::make_unique<EngineClock>()),
    m_windowHandler(nullptr),
    m_inputHandler(nullptr),
    m_app(nullptr)
{}

void Engine::Update(const float deltaTime)
{
    if(m_windowHandler)
    {
        m_windowHandler->ProcessEvents();
    }
    
    if(m_inputHandler)
    {
        m_inputHandler->Update();
    }
	
    if(m_app)
    {
        m_app->Update(deltaTime);
    }

    if(m_inputHandler)
    {
        if(m_inputHandler->IsKeyDown(256))
        {
            m_isRunning = false;
        }
    }
}

bool Engine::Start(const unsigned fps, const int width, const int height, const std::string& name)
{
    m_isRunning = false;
    
    m_clock->SetFPS(fps);
    
    m_windowHandler = std::make_shared<GLFWWindowHandler>();
    if(!m_windowHandler->InitializeWindow(width, height, name))
    {
        return false;
    }
    
    m_inputHandler = std::make_shared<GLFWInputHandler>();
    if(!m_inputHandler->Initialize(m_windowHandler.get()))
    {
        return false;
    }
    
    m_isRunning = true;
    return true;
}

bool Engine::LoadApp(IApp* app)
{
    if(!app)
    {
        return false;
    }
    m_app.reset(app);
    return m_app->Enter();
}

void Engine::Run()
{
    while(m_isRunning)
    {
        m_clock->UpdateFrameTicks();
        Update(m_clock->GetDeltaTime());
        Sleep(m_clock->GetSleepTime(m_clock->GetFPS()));    // Note: Not optimal and should be replaced with a better sleep function
    }

    if(!m_isRunning)
    {
        Shutdown();
    }
}

void Engine::Shutdown()
{
    m_isRunning = false;

    if(m_app)
    {
        m_app->Exit();
        m_app.reset();
    }

    if(m_windowHandler)
    {
        m_windowHandler->Shutdown();
        m_windowHandler.reset();
    }
}
