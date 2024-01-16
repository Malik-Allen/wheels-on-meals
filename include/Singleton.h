// MIT License, Copyright (c) 2024 Malik Allen

#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template <typename T>
class Singleton
{
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    
    inline static std::unique_ptr<T> g_instance = nullptr;
    friend std::default_delete<T>;

protected:    
    Singleton() = default;
    virtual ~Singleton() = default;
    
public:
    static T* Get()
    {
        if(!g_instance)
        {
            g_instance.reset(new T());
        }
        
        return g_instance.get();
    }
};

#endif // SINGLETON_H