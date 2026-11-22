#include "../include/my-radar.hpp"


void DrawMenu() {
    // Drawing Rectabgle Menu
    int currentwitdh = GetScreenWidth();
    int currentheight = GetScreenHeight();
    int size_x = currentwitdh / 2;
    int size_y = currentheight / 2;
    int centerX = size_x / 2;
    int centerY = size_y / 2;
    DrawRectangleLines(centerX, centerY, size_x, size_y, GREEN);
    // Drawing Button of Menu
    // 1- Button Start Simulation
    DrawRectangleLines(centerX + 50, centerY + 10, size_x - 100, size_y / 4, BLUE);
    DrawText("Start Simulation", centerX + 100, centerY + 10 + size_y / 8, 20, BLUE);
    // 2- Button Load Simulation
    DrawRectangleLines(centerX + 50, centerY + centerY - 50, size_x - 100, size_y / 4, BLUE);
    DrawText("Load Simulation", centerX + 100, centerY + centerY - 50 + size_y / 8, 20, BLUE);
    // 3- Button Exit Simulation
    DrawRectangleLines(centerX + 50, centerY * 2 + 75, size_x - 100, size_y / 4, BLUE);
    DrawText("Exit Simulation", centerX + 100, centerY * 2 + 75 + size_y / 8, 20, BLUE);
    // Mouse pos
    int x = GetMouseX();
    int y = GetMouseY();
    if ((x >= centerX + 50 && x <= centerX + size_x - 100) && (y >= centerY + 10 && y <= centerY + size_y / 4)) {
        DrawRectangleLines(centerX + 50, centerY + 10, size_x - 100, size_y / 4, RED);
    }
    if ((x >= centerX + 50 && x <= centerX + size_x - 100) && (y >= centerY + centerY - 50 && y <= centerY + centerY - 50 + size_y / 4)) {
        DrawRectangleLines(centerX + 50, centerY + centerY - 50, size_x - 100, size_y / 4, RED);
    }
    if ((x >= centerX + 50 && x <= centerX + size_x - 100) && (y >= centerY * 2 + 75 && y <= centerY * 2 + 75 + size_y / 4)) {
        DrawRectangleLines(centerX + 50, centerY * 2 + 75, size_x - 100, size_y / 4, RED);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            CloseWindow();
            exit(0);
        }
    }
}

void loop_simulation(parsing_t parse) {
    //Inite Window
    int FPS = 20;
    InitWindow(WIDTH, HEIGHT, "My Radar");
    SetTargetFPS(20);
    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawMenu();
        EndDrawing();
    }
    CloseWindow();
}