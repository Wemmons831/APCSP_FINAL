#include "raylib.h"
class Ball
{
    public:
    int rad;
    Color color;
    Vector2 position;
    bool warp;
    Vector2 force = {0,0}
    Ball(Vector2 _position,int _rad, Color _color, _wrap = true)
    {
        rad = _rad;
        color = _color;
        position = _position;
        wrap = _wrap;
    }
    void Update()
    {
        posistion = Vector2Add(posistion,force)
        if(wrap){
            if(posistion.x > 800){
                posistion.x = 0;
            }
            if(posistion.x < 0){
                posistion.x = 800
            }
            if(posistion.y > 450){
                posistion.y = 0
            }
            if(posistion.y < 0){
                posistion.y = 450
            }
        }
    }
    void Draw()
    {
        DrawCircle(position.x,position.y,rad,color);
    }
        
};