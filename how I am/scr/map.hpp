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
        DrawSphere(npc.cord,4.0f, DARKBLUE);
        DrawCube(Vector3{0,-1,0}, 600, 1, 600, DARKGREEN);
        DrawGrid(600, 1.0f);
        DrawCube(Vector3{10,0,10},4,15,4,BLUE);
    }

}