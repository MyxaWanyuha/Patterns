#include <iostream>
#include "Delegate.h"

class Sound
{
public:
    void Play()
    {
        std::cout << "Sound\n";
    }
};

class Effect
{
public:
    void Play()
    {
        std::cout << "Effect\n";
    }
};

class Car
{
public:
    void Move()
    {
        OnCarMove.Notify();
    }

    Delegate<void()> OnCarMove;
};

int main()
{
    Sound sound;
    Effect fx;
    Car car;
    auto f1 = [&]() { return sound.Play(); };
    auto f2 = [&]() { return fx.Play(); };

    car.OnCarMove.AddListener(f1);
    car.OnCarMove.AddListener(f2);
    
    car.Move();
}