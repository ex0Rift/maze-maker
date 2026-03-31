#include <iostream>
#include <array>
#include "raylib.h"
#include "map.hpp"

int main(){
    //==
    // Initialisation
    //==

    Map map({5,5});

    //vars

    // true = 3D false = 2D
    bool camera_mode = true;

    const int rows = 5;
    const int collumns = 5;
    std::array<std::array<int, rows>,collumns> tile_map =
    {{
        {0,1,0,0,1},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,0,0,0,0},
        {0,0,0,0,1}
    }};

    int scale = 5;

    //window setup
    InitWindow(1000,600,"3d-raylib");
    SetTargetFPS(60);

    DisableCursor();

    //camera for 3D
    Camera camera = {0};
    camera.position = (Vector3){10.0f, 2.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

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

            BeginMode3D(camera);
                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < collumns; j++){
                        if (tile_map[i][j] == 1){
                            DrawCube({(i*scale)+2.5f,2.5f,(j*scale)+2.5f},scale,5.0f,scale,GREEN);
                        }
                    }
                }


                DrawGrid(30,5.0f);
            EndMode3D();

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}