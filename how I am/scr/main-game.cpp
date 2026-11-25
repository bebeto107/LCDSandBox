#include <iostream>
#include <raylib.h>
#include "Npc1.hpp"
#include "colisions.hpp"
#include "map.hpp"
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
    float sensitive = 0.25f;
    DisableCursor();
    //--------------------------------------
    Vector3 modelposition;
    Vector3 null {0.0f, 0.0f , 0.0f};
    bool walk = false;
    //visble--------------------------------
    bool visible_gameplay = false;
    bool visible_menu = true;
    bool visible_pMenu = false;
    //menu----------------------------------
    Vector2 Mouse;

    
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
        if(IsKeyPressed(KEY_TAB)){
            visible_pMenu = !visible_pMenu;
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
        if (CheckCollisionPointRec(Mouse, cbm1))
        {
            cbm1.width = 1100;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                visible_menu = false;
                visible_gameplay = true;

            }
            
        }else{
            cbm1.width = 1000;
        }
        if (CheckCollisionPointRec(Mouse, cbm2))
        {
            cbm2.width = 1100;          
        }else{
            cbm2.width = 1000;
        }
        if (CheckCollisionPointRec(Mouse, cbmp1))
        {
            cbmp1.width = 700.0f;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                visible_pMenu = false;
            }
            
        } else{
            cbmp1.width = 650.0f;
        }
        if (CheckCollisionPointRec(Mouse, cbmp2))
        {
            cbmp2.width = 700.0f;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
               CloseWindow(); 
            }
            
        } else{
            cbmp2.width = 650.0f;
        }


        
        
        //Visuals
        BeginDrawing();
            ClearBackground(GRAY);
            

            if (visible_gameplay == true)
            {
                BeginMode3D(camera);
                DrawSphere(modelposition, 3.0f,RED);
                dev_map();
                map1();
                EndMode3D();
                DrawText(TextFormat("cords:\n %f \n %f \n %f", camera.position.x, camera.position.y, camera.position.z), 80, 10, 20,RED);
            }
            if (visible_pMenu == true && visible_menu == false){
                DrawRectangle(0,0,600,800,BLACK);
                DrawRectangle(cbmp1.x, cbmp1.y, cbmp1.width, cbmp1.height, DARKPURPLE);
                DrawRectangle(cbmp2.x, cbmp2.y, cbmp2.width, cbmp2.height, DARKPURPLE);
                DrawText("LCD SAND BOX \n press Tab to continue \n press Esc to quit", 0, 0, 40, WHITE);
            }
            if (visible_menu == true)
            {

                DrawRectangle(cbm1.x, cbm1.y, cbm1.width, cbm1.height, BLACK);
                DrawRectangle(cbm2.x, cbm2.y, cbm2.width, cbm2.height, BLACK);
                DrawText("LCD SAND BOX \n press Enter to start \n press Esc to quit", 100, 200, 80, WHITE);


            }
            DrawRectangle(Mouse.x, Mouse.y, 10,10, BLACK);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;

}