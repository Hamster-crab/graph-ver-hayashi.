#include "raylib.h"
#include <cstdlib>

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Rectangle graph = { 80, 230, 190, 60 };
    bool graphcolor = false;
    bool graphsummon = false;

    Rectangle calc = { 500, 230, 190, 60 };
    bool calccolor = false;
    bool calcsummon = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, graph))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                graphcolor = false;
                graphsummon = true;
            }
            else
            {
                graphcolor = true;
            }
        }
        else graphcolor = false;

        if (CheckCollisionPointRec(mousePoint, calc))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                calccolor = false;
                calcsummon = true;
            }
            else
            {
                calccolor = true;
            }
        }
        else calccolor = false;
        
        if (graphsummon)
        {
            #ifdef _WIN32
                system("inm.exe"); // Windows の場合
            #else
                system("./app/graph"); // Linux または macOS の場合
            #endif

            graphsummon = false;
        }

        if (calcsummon)
        {
            // #ifdef _WIN32
            //     system("inm.exe"); // Windows の場合
            // #else
            //     system("./app/graph"); // Linux または macOS の場合
            // #endif

            calcsummon = false;
        }
        

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(graph.x, graph.y, graph.width, graph.height, GRAY);
        DrawRectangle(graph.x + 5, graph.y + 5, graph.width - 10, graph.height - 10, WHITE);
        if (graphcolor) DrawText("GRAPH", graph.x + 5, graph.y + 5, 51, GRAY);
        else if (!graphcolor) DrawText("GRAPH", graph.x + 5, graph.y + 5, 51, BLACK);

        DrawRectangle(calc.x, calc.y, calc.width, calc.height, GRAY);
        DrawRectangle(calc.x + 5, calc.y + 5, calc.width - 10, calc.height - 10, WHITE);
        if (calccolor) DrawText("CALC", calc.x + 5, calc.y + 5, 51, GRAY);
        else if (!calccolor) DrawText("CALC", calc.x + 5, calc.y + 5, 51, BLACK);
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}