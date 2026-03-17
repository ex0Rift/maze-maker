#include "raylib.h"

int main(){
    //==
    // Initialisation
    //==
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



        //--
        //Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawCube({0.0f, 1.0f, 0.0f},2.0f,2.0f,2.0f,RED);


                DrawGrid(30,1.0f);
            EndMode3D();

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}