#include <iostream>
#include <array>
#include "raylib.h"
#include "map.hpp"

int main(){
    //==
    // Initialisation
    //==
    Map map({5,5},5);

    //vars

    // true = 3D false = topdown
    bool camera_mode = true;

    //window setup
    InitWindow(1000,600,"3d-raylib");
    SetTargetFPS(60);

    DisableCursor();

    //camera for 3D
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 2.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    //camera for top down view
    Camera3D topDown = {0};
    topDown.position = (Vector3){0.0f, 200.0f, 0.0f};
    topDown.target = (Vector3){0.0f, 0.0f, 0.0f};
    topDown.up = (Vector3){0.0f, 0.0f, -1.0f};
    topDown.fovy = 40.0f;
    topDown.projection = CAMERA_ORTHOGRAPHIC;


    map.tile_map[2][2] = 1;

    //==
    // Mainloop
    //==
    while (!WindowShouldClose()){
        //--
        //Logic
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);

        //change camera mode if "1" key is pressed 
        if (IsKeyPressed(KEY_ONE)) {
            camera_mode = !camera_mode;
        }


        //--
        //Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);
            if (camera_mode)BeginMode3D(camera);
            if (!camera_mode)BeginMode3D(topDown);
                
                //drawing the map
                for (int i = 0; i < map.map_perams.y; i++){
                    for (int j = 0; j < map.map_perams.x; j++){
                        if (map.tile_map[i][j] == 1){
                            DrawCube({(i*map.scale)+2.5f,2.5f,(j*map.scale)+2.5f},map.scale,5.0f,map.scale,GREEN);
                        }
                    }
                }

                //centre point marker
                DrawCube({0.0f,2.5f,0.0f},2.0f,5.0f,1.0f,RED);

                //draw the floor grid
                DrawGrid(30,5.0f);
            if (camera_mode)EndMode3D();
            if (!camera_mode)EndMode3D();

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}