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

    Grid grid(5, 5, {1280, 550});

    // home screen stuff
    int frame = 0;
    bool down = false;
    Rectangle difficulty = {static_cast<float>(screenWidth/2 - 150),static_cast<float>(screenHeight/2 + 25), 300, 75};
    Rectangle start = {static_cast<float>(screenWidth / 2 - 150), static_cast<float>(screenHeight / 2 + 150), 300, 75};
    printf("X: %f, Y: \n", difficulty.x,difficulty.y);
    char* currentDifficulty = "EASY";
    
    int currentylDrawingColor = 0;
    int currentColor = 0;
    int round = 0;
    int startTime;
    int endTime;
    bool hidden = false;
    int num_of_correct = 0;
    int wrongs = 0;
    int how_many_to_reveal = 0;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button  or ESC key
    {
        switch(screen)
        {
            case 0:
                if(IsMouseButtonPressed(0)){
                    if(CheckCollisionPointRec({float(GetMouseX()),float(GetMouseY())},difficulty)){
                        if(currentDifficulty == "EASY"){
                            currentDifficulty = "MEDIUM";
                        }
                        else if (currentDifficulty == "MEDIUM")
                        {
                            currentDifficulty = "HARD";
                        }
                        else if (currentDifficulty == "HARD")
                        {
                            currentDifficulty = "EASY";
                        }    
                    }
                    if (CheckCollisionPointRec({float(GetMouseX()), float(GetMouseY())},start)){
                        if (currentDifficulty == "EASY")
                        {
                            grid = Grid(3,3,{1280,550});
                            
                        }
                        else if (currentDifficulty == "MEDIUM")
                        {
                            grid = Grid(4, 4, {1280, 550});
                        }
                        else if (currentDifficulty == "HARD")
                        {
                            grid = Grid(5, 5, {1280, 550});
                        }
                        startTime = GetTime();
                        endTime = GetTime() + 5;
                        grid.array[0].reveeled = true;
                        screen = 1;
                        round = 0;
                        wrongs = 0;
                        num_of_correct = 0;
                        how_many_to_reveal = 0;
                    }
                }
                
                BeginDrawing();
                    if(down){
                        frame -= 1;
                    }
                    else{
                        frame++;
                    }
                    if(frame > 60){
                        down = !down;
                    }
                    if(frame == 0){
                        down = !down;
                    }
                    ClearBackground(RAYWHITE);
                    DrawText("Color Code",GetScreenWidth()/2 - (MeasureText("Color Code",24 + frame)/2),GetScreenHeight()/2 - 125, 24+ frame, BLACK);
                    DrawRectangleRec(difficulty, BLUE);
                    DrawText(currentDifficulty, difficulty.x + difficulty.width/2 - MeasureText(currentDifficulty,32)/2, difficulty.y + difficulty.height/2,32,BLACK);
                    //start stuff
                    DrawRectangleRec(start,BLUE);
                    DrawText("START", start.x + start.width/2 - MeasureText("START", 32)/2, start.y + start.height/2,32, BLACK);
                    
                EndDrawing();
                break;
            case 1:
                if(IsMouseButtonPressed(0)){
                    currentylDrawingColor = 0;
                    for( Color i : colors)
                    {
                        if (CheckCollisionPointRec({float(GetMouseX()), float(GetMouseY())}, {float(50) + (200 * currentylDrawingColor), 610, 150, 105})){
                            currentColor = currentylDrawingColor;
                        }
                        currentylDrawingColor++;
                    }
                }
                startTime = GetTime();
                if(endTime - startTime <= 0  && !hidden){
                    for(int i = 0; i != grid.rows * grid.columns; i++){
                        grid.array[i].reveeled = false;
                    }
                    hidden = true;

                }
                if (hidden)
                {
                    for (int i = 0; i != round + 1; i++)
                    {
                        if (IsMouseButtonPressed(0))
                        {
                            if (CheckCollisionPointRec({float(GetMouseX()), float(GetMouseY())}, {(grid.array[i].position.x * grid.size_of_square.x) + 0, (grid.array[i].position.y * grid.size_of_square.y) + 50, grid.size_of_square.x, grid.size_of_square.y}))
                            {
                                if (currentColor == grid.array[i].color && !grid.array[i].reveeled)
                                {
                                    grid.array[i].reveeled = true;
                                    num_of_correct++;
                                }
                                else {wrongs++;
                                printf("here \n");
                                }
                            }
                        }
                    }
                }
                if(round + 1 == num_of_correct){
                    round++;
                    
                    hidden = false;
                    endTime = GetTime() + 5;
                    num_of_correct = 0;
                    how_many_to_reveal++;
                    for(int i =0; i != how_many_to_reveal + 1; i++){
                        grid.array[i].reveeled = true;
                    }
                }
                if (round == grid.rows * grid.array){
                    screen = 2;
                }
                if(wrongs == 3){
                    screen = 3;
                }
                BeginDrawing();

                    ClearBackground(RAYWHITE);
                    DrawText(TextFormat("%.*s", wrongs * 3, "X  X  X  X  X  X"), 640, 10, 24, RED);
                    DrawText(TextFormat("Round %i/%i",round,grid.rows*grid.columns),10,10,24,BLACK);
                    if(!hidden){DrawText(TextFormat("Hiding in: %d", endTime - startTime),1000,10,24,BLACK);}
                    else{DrawText("Select the correct Colors",900,10,24,BLACK);}
                    currentylDrawingColor = 0;
                    for( Color i : colors){
                        DrawRectangle(50 + (200 * currentylDrawingColor), 610,150,105,i);
                        if(currentylDrawingColor == currentColor){
                            DrawRectangleLinesEx({float(50) + (200 * currentylDrawingColor), 610, 150, 105},5.0f, BLACK);
                        }
                        currentylDrawingColor++;
                    }
                    
                    
                    grid.Draw({0,50});
                EndDrawing();
                break;
            case 2:
                if (IsMouseButtonPressed(0) && CheckCollisionPointRec({float(GetMouseX()), float(GetMouseY())},start))
                {
                    screen = 0;
                }
                BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawText(TextFormat("CONGRATS YOU BEAT %s MODE", currentDifficulty), GetScreenWidth() / 2 - MeasureText(TextFormat("CONGRATS YOU BEAT %s MODE", currentDifficulty), 54)/ 2, GetScreenHeight() / 2 - 100, 54, BLACK);
                    DrawRectangleRec(start, BLUE);
                    DrawText("CONTINUE", start.x + start.width / 2 - MeasureText("CONTINUE", 32) / 2, start.y + start.height / 2, 32, BLACK);
                EndDrawing();
                break;
            case 3:
                if (IsMouseButtonPressed(0) && CheckCollisionPointRec({float(GetMouseX()), float(GetMouseY())}, start))
                {
                    screen = 0;
                }
                BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawText(TextFormat("YOU FAILED", currentDifficulty), GetScreenWidth() / 2 - MeasureText("YOU FAILED", 54) / 2, GetScreenHeight() / 2 - 100, 54, RED);
                    DrawRectangleRec(start, BLUE);
                    DrawText("CONTINUE", start.x + start.width / 2 - MeasureText("CONTINUE", 32) / 2, start.y + start.height / 2, 32, BLACK);
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