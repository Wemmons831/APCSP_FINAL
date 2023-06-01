#include "raylib.h"
#include "vector"
#include "cmath"
#include <stdio.h>
struct Square {
    Vector2 position;
    Color color;
    std::vector<int> objects;
};
class Grid
{   
public:    
    int rows;
    int columns;
    std::vector<Square> array;
    Vector2 size;
    Vector2 size_of_square;
    Grid(int _columns, int _rows,Vector2 _size, Color starting_color = RED)
    {
        rows = _rows;
        columns = _columns;
        size = _size;
        for(int i = 0; i != rows * columns; i++)
        {
           
            array.push_back({{static_cast<float>(i/(columns)),static_cast<float>(i % columns)},starting_color,{}});
        }
        size_of_square = {static_cast<float>(GetScreenWidth())/columns,static_cast<float>(GetScreenHeight())/rows}; // might be some issues with int/float
        printf("size of array %i \n", array.size());
    }
    
    void Draw(Vector2 position,int thickness = 5)
    {
        //draw lines
        DrawLineEx(position,{position.x + size.x, position.y}, thickness, BLACK);
        DrawLineEx(position,{position.x, position.y + size.y}, thickness, BLACK);
        for(int i = 0; i != columns; i++){
            DrawLineEx({position.x + ((size.x/columns) * (i+1)),position.y}, {position.x + ((size.x/columns) * (i+1)), position.y + size.y},thickness,BLACK);
        }
        for(int i = 0; i != rows; i++){
            DrawLineEx({position.x,position.y + ((size.y/rows) * (i+1))}, {position.x + size.x, position.y + ((size.y/rows) * (i+1))},thickness,BLACK);
        }
        // draw colors
        for(Square & i : array)
        {
            printf("X: %f, Y: %f \n",(i.position.x + 1 ) * size_of_square.x, (i.position.y +1) * size_of_square.y);
            DrawRectangle((i.position.x + 1 ) * size_of_square.x, (i.position.y +1) * size_of_square.y, size_of_square.x,size_of_square.y, i.color );
        }
    }
};