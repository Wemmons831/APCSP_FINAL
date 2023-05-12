#include "raylib.h"
class Ball
{
    public:
    int rad;
    Color color;
    Vector2 position;
    Ball(Vector2 _position,int _rad, Color _color)
    {
        rad = _rad;
        color = _color;
        position = _position;
    }
    void Update(){}
    void Draw()
    {
        DrawCircle(position.x,position.y,rad,color);
    }
        
}