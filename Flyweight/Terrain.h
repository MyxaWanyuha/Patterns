#pragma once
#include <string>

class Terrain
{
public:
    Terrain(const std::string& name, int speed)
        :m_Name(name), m_Speed(speed) {}
 
    const std::string& GetName() const { return m_Name; }
    int GetSpeed() const { return m_Speed; }

private:
    std::string m_Name;
    int m_Speed;
};
