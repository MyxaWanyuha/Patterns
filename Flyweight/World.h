#pragma once
#include "Terrain.h"

class World
{
public:
    World()
        : m_Grass("Grass", 2), m_Dirt("Dirt", 1), m_Road("Road", 5)
    {
        for(int x = 0; x < MapWidth; ++x)
            for (int y = 0; y < MapHeight; ++y)
            {
                auto r = rand() % 10;
                if (r <= 3)
                    m_Map[x][y] = &m_Grass;
                else if (r <= 7)
                    m_Map[x][y] = &m_Dirt;
                else
                    m_Map[x][y] = &m_Road;
            }
    }

    const Terrain& GetTile(int x, int y) const { return *m_Map[x][y]; }

    constexpr static int MapWidth = 5;
    constexpr static int MapHeight = 5;
private:
    Terrain m_Grass, m_Dirt, m_Road;
    Terrain* m_Map[MapWidth][MapHeight];
};