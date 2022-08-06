#include <iostream>
#include "Monster.h"

int main()
{
    Pudge pudge(10);
    Monster* monster = pudge.Clone();
    delete monster;
}