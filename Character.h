#pragma once
#include "State.h"

enum KeyCode
{
    Space
};

class Input
{
public:
    static bool IsKeyPressed(KeyCode key) { return true; }
};

class Character
{
public:
    Character()
        : m_CurrentState(m_IdleState)
    {
    }
    
    void Update()
    {
        // You can use "BaseState* m_CurrentState", but these are extra memory allocations.
        // BaseState* newState = m_CurrentState->HandleInput(*this, Input::IsKeyPressed(KeyCode::Space));
        State newState = m_CurrentState.HandleInput(*this, Input::IsKeyPressed(KeyCode::Space));
        if (newState != State::None)
        {
            switch (newState)
            {
            case State::Idle:
                m_CurrentState = m_IdleState;
                break;
            case State::Jump:
                m_CurrentState = m_jumpState;
                break;
            }
        }
    }

private:
    BaseState& m_CurrentState;
    IdleState m_IdleState;
    JumpState m_jumpState;
};