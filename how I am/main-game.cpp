#include <iostream>
#include <raylib.h>
#include <rcamera.h>
#include <cstdlib>
#include "Npc1.hpp"
using namespace std;
Npc1 npc; 
int main (){
    InitWindow(1200, 800, "Proto-LCD SAND BOX");
    InitAudioDevice();
    SetTargetFPS(60);

    //camera settings----------------------
    Camera3D camera = {
        .position   = { 6.0f, 6.0f, 6.0f },
        .target     = { 0.0f, 0.0f, 0.0f },
        .up         = { 0.0f, 1.0f, 0.0f },

        .fovy       = 45.0f,
        .projection = CAMERA_PERSPECTIVE,
    };
    int cameraMode = CAMERA_FIRST_PERSON;
    float sensitive = 0.5f;
    DisableCursor();
    //--------------------------------------
    Vector3 modelposition;
    Vector3 null {0.0f, 0.0f , 0.0f};
    bool walk = true;
    //visble--------------------------------
    bool visible_gameplay = false;
    bool visible_menu = true;
    //menu----------------------------------
    Vector2 Mouse;
    Rectangle cbm1 = {100,280,800, 80};

    while (!WindowShouldClose())
    {

        //Game controls
        //delta
        float dt = GetFrameTime();
        if(IsKeyPressed(KEY_ENTER) && visible_menu == true){
            visible_menu = false;
            visible_gameplay = true;
        }
        if(IsKeyPressed(KEY_F1)){
            EnableCursor();
        }
        if(IsKeyPressed(KEY_F2)){
            DisableCursor();
        }

        float speed = IsKeyDown(KEY_LEFT_SHIFT) ? 15.0f : 5.0f;  
        Vector3 move = {
            (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * speed * dt,  
            (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * speed * dt,  
            0.0f
        };
        Vector3 rot = { GetMouseDelta().x * sensitive, GetMouseDelta().y * sensitive, 0.0f };
        //Updatade
        Mouse = GetMousePosition();
        UpdateCameraPro(&camera, move, rot, 0.0f);
        modelposition = camera.position;
        Vector3 AImovs{npc.x, 6.0 , npc.z};
        if (npc.x <= 10 && walk == true)//redo from scratch beacause this is shit
        {
            npc.x += 0.05;
        }else
        {
            npc.x -= 0.05;
        }
        if (npc.x >= 10)
        {
            walk = !walk;
        }
        if (CheckCollisionPointRec(Mouse, cbm1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            visible_menu = false;
            visible_gameplay = true;
        }
        
        
        //Visuals
        BeginDrawing();
            ClearBackground(GRAY);

            if (visible_gameplay == true)
            {
                BeginMode3D(camera);
                DrawSphere(modelposition, 3.0f,RED);
                DrawSphere(AImovs, 4.0f, DARKBLUE);
                DrawGrid(100, 1.0f);
                EndMode3D();
                DrawText(TextFormat("cords:\n %f \n %f \n %f", camera.position.x, camera.position.y, camera.position.z), 80, 10, 20,RED);
            }
            if (visible_menu == true)
            {
                DrawRectangle(cbm1.x, cbm1.y, cbm1.width, cbm1.height, BLACK);
                DrawText("LCD SAND BOX \n press Enter to start \n press Esc to quit", 100, 200, 80, WHITE);

            }
            DrawRectangle(Mouse.x, Mouse.y, 10,10, BLACK);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;

}