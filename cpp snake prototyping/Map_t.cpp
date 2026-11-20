#include "Map_t.h"

GridItem Map_t::GetIdentityOfItem(short2 pos)
{
    return mapGrid[pos.x][pos.y].GetID();
}

void Map_t::IdentifyAsItem(GridItem item, short2 pos)
{
    if (mapGrid[pos.x][pos.y].GetID() == GridItem::EMPTY)
    {
        mapGrid[pos.x][pos.y].SetID(item);
    }
}

void Map_t::UnidntifyItem(short2 pos)
{
    if (mapGrid[pos.x][pos.y].GetID() != GridItem::WALL)
    {
        mapGrid[pos.x][pos.y].SetID(EMPTY);
    }
}


bool& Map_t::AppleEaten()
{
    return appleEaten;
}

char Map_t::GetDisplayValueAt(short2 pos)
{
    mapGrid[pos.x][pos.y].GetDisplayValue();
}
