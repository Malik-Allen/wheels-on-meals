// MIT License, Copyright (c) 2019 Malik Allen

#ifndef APP_H
#define APP_H

class IApp
{
public:
    IApp() = default;
    virtual ~IApp()
    {
        Exit();
    }
    
    bool Enter()
    {
        return IApp_Enter();
    }
    
    void Update( const float deltaTime )
    {
        IApp_Update( deltaTime );
    }

    void Exit()
    {
        IApp_Exit();
    }    

private:
    virtual bool IApp_Enter() { return true; }
    virtual void IApp_Update( const float deltaTime ) {}
    virtual void IApp_Exit() {}
};

#endif // !APP_H