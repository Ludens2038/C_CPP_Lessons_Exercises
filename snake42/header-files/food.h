#pragma once
#include "raylib.h"
#include <deque>

class Food {
public:
    Vector2 position;
    Texture2D texture;

    Food(std::deque<Vector2> snakeBody);
    ~Food();

    void Draw();
    Vector2 generateRandomCell();
    Vector2 generateRandomPos(std::deque<Vector2> snakeBody);
};
