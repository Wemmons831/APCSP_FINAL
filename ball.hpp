#include "raylib.h"
class Ball
{
    public:
    int rad;
    Color color;
    Vector2 position;
    bool warp;
    Vector2 force = {0,0};
    Ball(Vector2 _position,int _rad, Color _color,bool _wrap = true)
    {
        rad = _rad;
        color = _color;
        position = _position;
        wrap = _wrap;
    }
    void Update()
    {
        position = Vector2Add(position,force);
        if(wrap){
            if(position.x > 800){
                position.x = 0;
            }
            if(position.x < 0){
                position.x = 800;
            }
            if(posistion.y > 450){
                position.y = 0;
            }
            if(position.y < 0){
                position.y = 450;
            }
        }
    }
    void Draw()
    {
        DrawCircle(position.x,position.y,rad,color);
    }
        
};