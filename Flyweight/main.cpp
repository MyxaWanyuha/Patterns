#include <iostream>
#include "World.h"

int main()
{
    World world;
    for (int x = 0; x < world.MapWidth; ++x)
    {
        for (int y = 0; y < world.MapHeight; ++y)
        {
            std::cout << world.GetTile(x, y).GetName() << '\t';
        }
        std::cout << '\n';
    }
}