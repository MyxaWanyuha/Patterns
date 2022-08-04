#include <iostream>
#include "CommandQueue.h"

int main()
{
    Character character;
    CommandQueue queue;

    queue.AddCommand(new MoveCommand(character, 1, 0));
    queue.AddCommand(new AddRotationCommand(character, 10));
    queue.AddCommand(new MoveCommand(character, 0, -5));
    queue.AddCommand(new AddRotationCommand(character, -1));
    queue.UndoLastCommand();
    queue.AddCommand(new MoveCommand(character, 0, 2));
    queue.UndoLastCommand();
    queue.BackToLastCommand();
    queue.AddCommand(new AddRotationCommand(character, 3));

    std::cout << "X: " << character.GetX() << " Y: " << character.GetY() << " Rot: " << character.GetRotation();
}
