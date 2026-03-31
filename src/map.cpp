#include "map.hpp"
#include "raylib.h"
#include <vector>


Map::Map(Vector2 inp_map_perams)
{
    map_perams = inp_map_perams;

    //resize the map size to desired size
    tile_map.resize(map_perams.y);
    for (auto& row : tile_map) {
        row.resize(map_perams.x);
    }
}