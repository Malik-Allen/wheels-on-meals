// MIT License, Copyright (c) 2019 Malik Allen

#ifndef ENGINECLOCK_H
#define ENGINECLOCK_H

#include "HighResTimer.h"

class EngineClock : public HighResTimer
{
    EngineClock( const EngineClock& ) = delete;
    EngineClock& operator=( const EngineClock& ) = delete;
    EngineClock( EngineClock&& ) = delete;
    EngineClock& operator=( EngineClock&& ) = delete;

public:
    EngineClock() :
        HighResTimer(),
        m_prevTicks( 0 ),
        m_currentTicks( 0 ),
        m_fps( 120 )
    {
        Reset();
    }
    
    ~EngineClock() = default;

    unsigned int GetFPS() const { return m_fps; }
    void SetFPS( unsigned int fps ) { m_fps = fps; }

    void Reset()
    {
        m_prevTicks = m_currentTicks = HighResTimer::GetCurrentTimeInMilliSeconds();
    }
    
    void UpdateFrameTicks()
    {
        m_prevTicks = m_currentTicks;
        m_currentTicks = HighResTimer::GetCurrentTimeInMilliSeconds();
    }
    
    float GetDeltaTime() const
    {
        return static_cast< float >( m_currentTicks - m_prevTicks ) * MILLISECONDS_TO_SECONDS;	// Conversion to seconds
    }
    
    unsigned int GetSleepTime( const unsigned int fps )
    {
        const unsigned int milliSecsPerFrame = SECONDS_TO_MILLISECONDS / fps;

        if( milliSecsPerFrame == 0 )
        {
            return 0;
        }

        const unsigned int sleepTime = milliSecsPerFrame - HighResTimer::GetCurrentTimeInMilliSeconds();

        if( sleepTime > milliSecsPerFrame )
        {
            return milliSecsPerFrame;
        }

        return sleepTime;
    }
    
    float GetCurrentTicks() const
    {
        return static_cast< float >( m_currentTicks ) * MILLISECONDS_TO_SECONDS;
    }

private:
    unsigned int m_prevTicks;
    unsigned int m_currentTicks;
    unsigned int m_fps;

};

#endif // !ENGINECLOCK_H