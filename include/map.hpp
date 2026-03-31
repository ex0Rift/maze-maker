#pragma once
#include <vector>
#include "raylib.h"

class Map{
private:
    Vector2 map_perams;
public:
    std::vector<std::vector<int>> tile_map;

    Map(Vector2 inp_map_perams);
};