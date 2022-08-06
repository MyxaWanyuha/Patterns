#pragma once

class Monster
{
public:
    Monster(int health)
        : m_Health(health)
    {
    }

    virtual ~Monster() = default;
    virtual Monster* Clone() = 0;
    int GetHealth() const { return m_Health; }
protected:
    int m_Health;
};

class Pudge : Monster
{
public:
    Pudge(int health)
        : Monster(health)
    {
    }

    virtual Monster* Clone() override
    {
        return new Pudge(*this);
    }
};
