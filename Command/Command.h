#pragma once
#include <string>
#include "Character.h"

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual std::string ToString() = 0;
};

class MoveCommand : public Command
{
public:
    MoveCommand(Character& character, int x, int y)
        : m_Character(character), m_X(x), m_Y(y), m_OldX(character.GetX()), m_OldY(character.GetY())
    {
    }

    virtual void Execute() override
    {
        m_Character.MoveTo(m_X, m_Y);
    }

    virtual void Undo() override
    {
        m_Character.MoveTo(m_OldX, m_OldY);
    }

    virtual std::string ToString() override
    {
        return "Move to: { " + std::to_string(m_X) + ", " + std::to_string(m_Y) + " }";
    }

private:
    Character& m_Character;
    int m_X, m_Y;
    int m_OldX, m_OldY;
};

class AddRotationCommand : public Command
{
public:
    AddRotationCommand(Character& character, float rotationToAdd)
        : m_Character(character), m_Rotation(rotationToAdd)
    {
    }

    virtual void Execute() override
    {
        m_Character.AddRotation(m_Rotation);
    }

    virtual void Undo() override
    {
        m_Character.AddRotation(-m_Rotation);
    }

    virtual std::string ToString() override
    {
        return "Rotation added: { " + std::to_string(m_Rotation) + " }";
    }

private:
    Character& m_Character;
    float m_Rotation;
};
