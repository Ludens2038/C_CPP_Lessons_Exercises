#pragma once
#include "snake.h"
#include "food.h"
#include "raylib.h"

class Game {
public:
    Snake snake;
    Food food;
    bool running;
    int score;
    Sound eatSound;
    Sound wallSound;

    Game();
    ~Game();

    void Draw();
    void Update();
    void checkCollisionWithFood();
    void checkColisionWithEdges();
    void checkCollisionWithTail();
    void GameOver();
};
