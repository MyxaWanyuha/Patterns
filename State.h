#pragma once

class Character;

enum class State
{
    None, Idle, Jump
};

class BaseState
{
public:
    virtual State HandleInput(Character& character, int button) = 0;
};

class IdleState : public BaseState
{
public:
    virtual State HandleInput(Character& character, int button)
    {
        return State::None;
    }
};

class JumpState : public BaseState
{
public:
    virtual State HandleInput(Character& character, int button)
    {
        if (button)
        {
            // Some code like:
            // character.Jump();
            return State::Jump;
        }
        return State::None;
    }
};