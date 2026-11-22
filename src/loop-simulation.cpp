#include "../include/my-radar.hpp"

void loop_simulation(parsing_t parse) {
    //Inite Window

    int FPS = 20;
    InitWindow(WIDTH, HEIGHT, "My Radar");
    SetTargetFPS(20);
    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }
    CloseWindow();
}