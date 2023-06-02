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
   
    Grid grid(5,5,{1270,710});
    
    // home screen stuff
    int frame = 0;
    bool down = false;
    Rectangle difficulty = {GetScreenWidth()/2 - 100, GetScreenHeight() + 50, 200, 75}


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
                    if(down){
                        frame -= 1;
                    }
                    else{
                        frame++;
                    }
                    if(frame > 60){
                        down != down
                    }
                    ClearBackground(RAYWHITE);
                    DrawText("Color Code",GetScreenWidth()/2 - (MeasureText("Color Code",24 + frame)/2),GetScreenHeight()/2 - 125, 24+ frame, BLACK);
                    DrawRectangleRec(difficulty, BLUE);
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