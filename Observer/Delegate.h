#pragma once
#include <functional>
#include <vector>

template<typename T>
class Delegate
{
public:
    using Fn = std::function<T>;
    void Notify()
    {
        for (const Fn& fn : m_Listeners)
            fn();
    }

    void AddListener(const Fn& fn)
    {
        m_Listeners.push_back(fn);
    }

private:
    std::vector<Fn> m_Listeners;
};