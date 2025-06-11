#pragma once
#include "raylib.h"
#include <deque>

class Snake {
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    Texture2D head;
    Texture2D tail;

    Snake();
    ~Snake();

    void Draw();
    void Update();
    void reset();
};
