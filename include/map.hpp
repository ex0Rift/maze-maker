#pragma once
#include <vector>
#include "raylib.h"

class Map{
public:
    std::vector<std::vector<int>> tile_map;
    Vector2 map_perams;
    int scale;

    Map(Vector2 inp_map_perams, int inp_scale);
    
    void AddSegment(int x, int y);
    void AddWall(Vector2 first, Vector2 last);
    bool Collide(Vector3 col1, float size1, Vector3 col2, float size2);
    void RemoveSegment(int x, int y);
};