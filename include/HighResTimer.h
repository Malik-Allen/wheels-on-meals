// MIT License, Copyright (c) 2019 Malik Allen

#ifndef HIGHRESTIMER_H
#define HIGHRESTIMER_H

#include <Windows.h>

#ifndef MILLISECONDS_TO_SECONDS
#define MILLISECONDS_TO_SECONDS (1 / 1000.0f)
#endif // !MILLISECONDS_TO_SECONDS

#ifndef MICROSECONDS_TO_SECONDS
#define MICROSECONDS_TO_SECONDS (1 / 1000000.0f)
#endif // !MICROSECONDS_TO_SECONDS

#ifndef MILLISECONDS_TO_MICROSECONDS
#define SECONDS_TO_MILLISECONDS (1000 / 1)
#endif // !MILLISECONDS_TO_MICROSECONDS

#ifndef SECONDS_TO_MICROSECONDS
#define SECONDS_TO_MICROSECONDS (1000000 / 1)
#endif // !SECONDS_TO_MICROSECONDS

class HighResTimer {
    HighResTimer(const HighResTimer&) = delete;
    HighResTimer& operator=(const HighResTimer&) = delete;
    HighResTimer(HighResTimer&&) = delete;
    HighResTimer& operator=(HighResTimer&&) = delete;
    
public:
    HighResTimer():
        frequency(),
        currentTicks()
    {
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&currentTicks);
    }
    
    virtual ~HighResTimer() = default;

    unsigned int GetCurrentTimeInMicroSeconds()
    {
        QueryPerformanceCounter(&currentTicks);			        // Retrieves the current value of the performance counter 'Ticks'
        currentTicks.QuadPart *= SECONDS_TO_MICROSECONDS;		// Conversion to microseconds to avoid a loss of percision when divinding by frequency
        currentTicks.QuadPart /= frequency.QuadPart;	        // Division by 'Ticks-per-second'
	
        return static_cast<unsigned int>(currentTicks.QuadPart);
    }
    
    unsigned int GetCurrentTimeInMilliSeconds()
    {
        QueryPerformanceCounter(&currentTicks);
        currentTicks.QuadPart *= SECONDS_TO_MILLISECONDS;					
        currentTicks.QuadPart /= frequency.QuadPart;

        return static_cast<unsigned int>(currentTicks.QuadPart);
    }

private:
    LARGE_INTEGER frequency;	// 'Ticks-per-second' 
    LARGE_INTEGER currentTicks;

    //**IMPORTANT: LARGE_INTEGER is a union that has member value called 'QuadPart' which stores a 64bit signed int
    // 'QuadPart' should be used for a compiler with support for 64-bit integers, where as 'HighPart' and 'LowPart' should be used otherwise.
};

#endif // !HIGHRESTIMER_H