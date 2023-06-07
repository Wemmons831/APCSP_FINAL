#include "raylib.h"
#include "vector"
#include "cmath"
#include <stdio.h>
std::vector<Color> colors = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE}; // possible colors
// struct that allows sqaure to be better
struct Square {
    Vector2 position;
    int color;
    bool reveeled = false;
};
class Grid
{   
public:    
    int rows;
    int columns;
    std::vector<Square> array;
    Vector2 size;
    Vector2 size_of_square;
    //constuctur that allows grid size and shape to change
    Grid(int _columns, int _rows,Vector2 _size, Color starting_color = RED)
    {
        rows = _rows;
        columns = _columns;
        size = _size;
        for(int i = 0; i != rows * columns; i++)
        {
           
            array.push_back({{static_cast<float>(i/(columns)),static_cast<float>(i % columns)},GetRandomValue(0,5)});
        }
        size_of_square = {size.x/columns, size.y/rows}; // might be some issues with int/float
        printf("size of array %i \n", array.size());
    }
    
    void Draw(Vector2 position,int thickness = 5)
    {
        
        // draw colors
        for(Square & i : array)
        {
            //printf("X: %f, Y: %f \n",(i.position.x + 1 ) * size_of_square.x, (i.position.y +1) * size_of_square.y);
            if(i.reveeled){
                DrawRectangle((i.position.x * size_of_square.x) + position.x, (i.position.y * size_of_square.y) + position.y, size_of_square.x,size_of_square.y, colors[i.color]);
            }
            else
            {
                DrawRectangle((i.position.x * size_of_square.x) + position.x, (i.position.y * size_of_square.y) + position.y, size_of_square.x, size_of_square.y, GRAY);
            }
        }
        
        //draw lines
        DrawLineEx(position,{position.x + size.x, position.y}, thickness, BLACK);
        DrawLineEx(position,{position.x, position.y + size.y}, thickness, BLACK);
        for(int i = 0; i != columns; i++){
            DrawLineEx({position.x + ((size.x/columns) * (i+1)),position.y}, {position.x + ((size.x/columns) * (i+1)), position.y + size.y},thickness,BLACK);
        }
        for(int i = 0; i != rows; i++){
            DrawLineEx({position.x,position.y + ((size.y/rows) * (i+1))}, {position.x + size.x, position.y + ((size.y/rows) * (i+1))},thickness,BLACK);
        }
        
    }
};