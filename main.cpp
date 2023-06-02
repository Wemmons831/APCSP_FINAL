#include "raylib.h"
#include "ball.hpp"
#include "grid.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    int screen = 0;
    int frame = 0
    Grid grid(5,5,{1270,710});
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch(screen)
        {
            case 0:
                BeginDrawing();
                    frame++
                    if(frame > 20){
                        frame = 0;
                    }
                    ClearBackground(RAYWHITE);
                    DrawText("Color Code",GetScreenWidth()/2 - (MeasureText("Color Code",24 + frame)/2),GetScreenHeight()/2, 24+ frame, BLACK);
                EndDrawing();
                break;
            case 1:
                BeginDrawing();

                    ClearBackground(GRAY);

                    grid.Draw({0,0});
                EndDrawing();
                break;

        }
       
        // Draw
        //----------------------------------------------------------------------------------
       
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}