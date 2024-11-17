#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    bool settings = false;
    bool hirei = false;
    bool hanpirei = false;
    double x = screenWidth / 2;
    double y = screenHeight / 2;

    Rectangle hireiOn = { 270, 80, 13, 13 };
    Rectangle hanpireiOn = { 650, 80, 13, 13};

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (settings)
            {
                if (CheckCollisionPointRec(mousePos, hireiOn))
                {
                    if (hirei) hirei = false;
                    else if (!hirei) hirei = true;
                }
                else if (CheckCollisionPointRec(mousePos, hanpireiOn))
                {
                    if (hanpirei) hanpirei = false;
                    else if (!hanpirei) hanpirei = true;
                }
            }
        }

        if (IsKeyPressed(KEY_S))
        {
            if (settings) settings = false;
            else if (!settings) settings = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, y, screenWidth, 2.8, GREEN);
        DrawRectangle(x, 0, 2.8, screenHeight, GREEN);
        DrawCircle (x, y, 4, BLACK);

        if (settings)
        {
            DrawRectangle(screenWidth / 100, screenHeight / 100, 880, 580, GRAY);
            DrawText("y = ax", 220, 20, 30, BLACK);
            DrawCircle(hireiOn.x, hireiOn.y, 18, BLACK);
            DrawCircle(hireiOn.x, hireiOn.y, hireiOn.width, WHITE);
            if (hirei) DrawCircle(270, 80, 8, GREEN);

            DrawText("y = a/x", 600, 20, 30, BLACK);
            DrawCircle(650, 80, 18, BLACK);
            DrawCircle(650, 80, 13, WHITE);
            if (hanpirei) DrawCircle(650, 80, 8, GREEN);

            DrawRectangle(730, 530, 150, 40, RED);
            DrawText("Done", 750, 538, 33, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}