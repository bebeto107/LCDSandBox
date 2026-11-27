#pragma once
#include <raylib.h>
#include <random>
#include "Npc1.hpp"

void load(){
    
}
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(50, 53);
    float cordenada_random =  dist(gen);
    

    if (map1_bool == true){
        ClearBackground(DARKBLUE);
        DrawSphere(npc.cord,4.0f, DARKPURPLE);
        
        DrawCube(Vector3{50,0,10},40,90,40,DARKBLUE);
        DrawCubeWires({50,0,10}, 40, 90, 40, BLACK);
        DrawCube(Vector3{50,0,60},30,90,40,MAROON);
        DrawCubeWires({50,0,60}, 30, 90, 40, BLACK);
        DrawSphere(Vector3{0,4500,0},4300, ORANGE);
        DrawCube(Vector3{50,0,130},30,90,40,DARKBROWN);
        DrawCubeWires({50,0,130}, 30, 90, 40, BLACK);

        DrawCube(Vector3{100,0,80},20,1000,30,MAROON);
        DrawCubeWires({100,0,80}, 20, 1000, 30, BLACK);
        DrawCube(Vector3{100,0,10},30,500,30,DARKBLUE);
        DrawCubeWires({100,0,10}, 30,500, 30, BLACK);

        DrawCube(Vector3{-80,0,100},30,100,40,MAROON);
        DrawCubeWires({-80,0,100}, 30, 100, 40, BLACK);
        DrawCube(Vector3{-80,0,10},40,100,40,DARKBLUE);
        DrawCubeWires({-80,0,10}, 40, 100, 40, BLACK);

        DrawCube(Vector3{cordenada_random,0,-50},40,90,40,PURPLE);
        DrawCubeWires({cordenada_random,0,-50}, 40, 90, 40, BLACK);
        
    }


}