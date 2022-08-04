#pragma once

class Character
{
public:
    Character()
        : m_X(0), m_Y(0), m_Rotation(0.0f) {}

    void MoveTo(int x, int y)
    {
        m_X = x;
        m_Y = y;
    }

    void AddRotation(float rotationToAdd)
    {
        m_Rotation += rotationToAdd;
    }

    int GetX() const { return m_X; }
    int GetY() const { return m_Y; }
    float GetRotation() const { return m_Rotation; }

private:
    int m_X, m_Y;
    float m_Rotation;
};