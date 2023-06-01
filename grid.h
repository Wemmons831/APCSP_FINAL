#include "raylib.h"
#include "vector"
#include "cmath"
struct Square {
    Vector2 position;
    Color color;
    std::vector<int> objects;
}
class Grid
{   
public:    
    int rows;
    int columns;
    std::vector<Square> array;
    Vector2 size;
    Grid(int _columns, int _rows,Vector2 _size, Color starting_color = RED)
    {
        rows = _rows;
        columns = _columns;
        size = _size;
        for(int i = 0; i != rows * columns; i++)
        {
            array.push_back({{floor(static_cast<float>(i)/(columns)), i % columns},starting_color,{}});
        }
    }
    
    void Draw(Vector2 position,int thickness = 5)
    {
        //draw lines
        for(int i = 0; i != columns; i++){
            DrawLineEx({position.y, position.x + ((size.x/columns) * (i+1))}, {position.y + size.y, position.x + ((size.x/columns) * (i+1))},thickness,BLACK);
        }
    }
};