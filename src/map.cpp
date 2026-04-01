#include "map.hpp"
#include "raylib.h"
#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>


Map::Map(Vector2 inp_map_perams, int inp_scale)
{
    map_perams = inp_map_perams;
    scale = inp_scale;

    //resize the map size to desired size
    tile_map.resize(map_perams.y);
    for (auto& row : tile_map) {
        row.resize(map_perams.x);
    }
}

void Map::AddSegment(int x, int y)
{
    tile_map[y][x] = 1;
}

void Map::AddWall(Vector2 first, Vector2 last)
{   
    // works out how many segments the line crosses
    int numPoints = std::gcd(std::abs((int)last.x - (int)first.x), std::abs((int)last.y - (int)first.y)) + 1;
    //divides by 1 to find out what the multiplier is for how many locations need to be worked out
    float multiplier = 1.0f / (float)numPoints;

    //loops through until multipler = 1 (if multiplier is 1 it has reached the end of the line)
    for (float i = 0.0f; i < 1; i += multiplier){
        //finds x and y place of where the cubes need to be placed along the line
        int x = first.x + i*(last.x - first.x);
        int y = first.y + i*(last.y - first.y);
        //adds segment to the tilemap
        AddSegment(x,y);
    }
}