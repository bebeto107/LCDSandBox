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
        DrawCube(Vector3{0,-1,0}, 1000, 1, 1000, DARKGREEN);
        DrawGrid(1000, 1.0f);
        DrawCube(Vector3{150,0,10},40,150,40,DARKBLUE);
        DrawCubeWires({150,0,10}, 40, 150, 40, BLACK);
        DrawCube(Vector3{150,0,60},30,100,40,MAROON);
        DrawCubeWires({150,0,60}, 30, 100, 40, BLACK);
        DrawSphere(Vector3{0,4500,0},4300, ORANGE);
        DrawSphereWires(Vector3{0,4500,0},4300,2,2,BLACK);
    }

}