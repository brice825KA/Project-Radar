#include "../include/my-radar.hpp"


void SetupTower(vector<tower_t> tower, Texture2D towerTexture) {
    float targetsize = 40.0f;
    float scale = targetsize / towerTexture.width;
    float towerWidth = (towerTexture.width * scale) / 2.0f;
    float towerHeight = (towerTexture.height * scale)  / 2.0f;
    for (const auto &i: tower) {
        // Draw Tower
        DrawTextureEx(towerTexture, (Vector2){i.pos_x, i.pos_y}, 0.0f, scale, WHITE);
        DrawCircleLines(i.pos_x + towerWidth, i.pos_y + towerHeight, i.rayon, RED);
    }
}

void DrawMenu(parsing_t parse, Texture2D towerTexture, Texture2D background) {
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
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            EndDrawing();
            Rectangle src = {0.0f, 0.0f, (float)background.width, (float)background.height};
            while(!WindowShouldClose()) {
                if (IsKeyPressed(KEY_Q)) {
                    break;
                }
                Rectangle dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};
                BeginDrawing();
                ClearBackground(BLACK);
                DrawTexturePro(background, src, dest, {0.0f, 0.0f}, 0.0f, RAYWHITE);
                SetupTower(parse.tour, towerTexture);
                EndDrawing();
            }
            BeginDrawing();
        }

    }
    if ((x >= centerX + 50 && x <= centerX + size_x - 100) && (y >= centerY + centerY - 50 && y <= centerY + centerY - 50 + size_y / 4)) {
        DrawRectangleLines(centerX + 50, centerY + centerY - 50, size_x - 100, size_y / 4, RED);
    }
    if ((x >= centerX + 50 && x <= centerX + size_x - 100) && (y >= centerY * 2 + 75 && y <= centerY * 2 + 75 + size_y / 4)) {
        DrawRectangleLines(centerX + 50, centerY * 2 + 75, size_x - 100, size_y / 4, RED);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            EndDrawing();
            UnloadTexture(towerTexture);
            UnloadTexture(background);
            CloseWindow();
            exit(0);
        }
    }
}

void loop_simulation(parsing_t parse) {
    //Inite Window
    int FPS = 20;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "My Radar");
    SetTargetFPS(60);
    Texture2D towerTexture = LoadTexture("src/assets/tour.png");
    Texture2D background = LoadTexture("src/assets/map.png");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawMenu(parse, towerTexture, background);
        EndDrawing();
  }
  UnloadTexture(towerTexture);
  UnloadTexture(background);
  CloseWindow();
}