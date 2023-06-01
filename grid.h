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
    int rows;
    int columns;
    std::vector<Square> array;
    Grid(int _columns, int _rows, Color starting_color = RED)
    {
        rows = _rows;
        columns = _columns;
        for(int i = 0; i != rows * columns, i++)
        {
            array.push_back({{floor(i/(columns)), i % columns},starting_color,{}});
        }
    }
};