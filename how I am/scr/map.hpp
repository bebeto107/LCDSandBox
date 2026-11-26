#pragma once
#include <raylib.h>
#include "Npc1.hpp"

bool dev_map_bool= false;
void dev_map(){
    Npc1 npc; 
    if (dev_map_bool == true){
        DrawSphere(npc.cord,4.0f, DARKBLUE);
        DrawGrid(600, 1.0f);
    }

}

bool map1_bool = true;
void map1(){
    Npc1 npc; 
    if (map1_bool == true){
        ClearBackground(DARKBLUE);
        DrawSphere(npc.cord,4.0f, DARKPURPLE);
        DrawCube(Vector3{0,-1,0}, 500, 1, 500, GRAY);
        DrawGrid(500, 1.0f);

        DrawCube(Vector3{50,0,10},40,30,40,DARKBLUE);
        DrawCubeWires({50,0,10}, 40, 30, 40, BLACK);
        DrawCube(Vector3{50,0,60},30,30,40,MAROON);
        DrawCubeWires({50,0,60}, 30, 30, 40, BLACK);
        DrawSphere(Vector3{0,4500,0},4300, ORANGE);
        DrawCube(Vector3{50,0,130},30,30,40,DARKBROWN);
        DrawCubeWires({50,0,130}, 30, 30, 40, BLACK);

        DrawCube(Vector3{100,0,80},30,40,40,MAROON);
        DrawCubeWires({100,0,80}, 30, 40, 40, BLACK);
        DrawCube(Vector3{100,0,10},40,40,40,DARKBLUE);
        DrawCubeWires({100,0,10}, 40, 40, 40, BLACK);

        DrawCube(Vector3{-80,0,100},30,40,40,MAROON);
        DrawCubeWires({-80,0,100}, 30, 40, 40, BLACK);
        DrawCube(Vector3{-80,0,10},40,40,40,DARKBLUE);
        DrawCubeWires({-80,0,10}, 40, 40, 40, BLACK);
        
    }

}