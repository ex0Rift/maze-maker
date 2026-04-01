#pragma once
#include <vector>
#include "raylib.h"

class Map{
public:
    std::vector<std::vector<int>> tile_map;
    Vector2 map_perams;
    int scale;

    Map(Vector2 inp_map_perams, int inp_scale);
};