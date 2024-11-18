#include "raylib.h"
#include <string>
#include <fstream>
#include <iostream>

void DrawTextInt(const char *text, int drawInt, int posX, int posY, int fontSize, Color color) {
    // textとdrawIntを1つの文字列に結合
    char buffer[256]; // 必要に応じてサイズを調整
    snprintf(buffer, sizeof(buffer), "%s%d", text, drawInt);
    
    // raylibのDrawText関数を使って結合した文字列を描画
    DrawText(buffer, posX, posY, fontSize, color);
}

int main()
{
    const int screenWidth = 340;
    const int screenHeight = 510;

    InitWindow(screenWidth, screenHeight, "calc");

    Rectangle AC = { 0, 100, 50, 50 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();

        BeginDrawing();
        ClearBackground(GRAY);
        DrawRectangle(AC.x, AC.y, AC.width, AC.height, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}