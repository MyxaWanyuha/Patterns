#pragma once
#include <vector>
#include <memory>
#include "Command.h"

class CommandQueue
{
public:
    void AddCommand(Command* command)
    {
        if (!command)
            return;

        // Delete last commands after undo
        for (int64_t i = m_Commands.size() - 1; i > m_LastCommandIndex; --i)
            m_Commands.pop_back();
        command->Execute();
        m_Commands.push_back(std::unique_ptr<Command>(command));
        ++m_LastCommandIndex;
    }

    // Ctrl + Z
    void UndoLastCommand()
    {
        if (m_LastCommandIndex == 0)
            return;
        m_Commands[m_LastCommandIndex]->Undo();
        --m_LastCommandIndex;
    }

    // Ctrl + Y
    void BackToLastCommand()
    {
        if (m_LastCommandIndex == m_Commands.size() - 1)
            return;
        ++m_LastCommandIndex;
        m_Commands[m_LastCommandIndex]->Execute();
    }
private:
    std::vector<std::unique_ptr<Command>> m_Commands;
    int64_t m_LastCommandIndex = -1;
};