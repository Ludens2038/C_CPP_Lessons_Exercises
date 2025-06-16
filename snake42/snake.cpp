#include "header-files/snake.h"

#include "raymath.h"
#include "header-files/utils.h"

Snake::Snake() {
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
    addSegment = false;

    Image headImg = LoadImage("assets/head.png"); // Passe Pfad/Name an!
    ImageResize(&headImg, 40, 40);
    head = LoadTextureFromImage(headImg);
    UnloadImage(headImg);

    Image tailImg = LoadImage("assets/pfirsich.png");
    ImageResize(&tailImg, 35, 35);
    tail = LoadTextureFromImage(tailImg);
    UnloadImage(tailImg);
}

Snake::~Snake() {
    UnloadTexture(head);
    UnloadTexture(tail);
}

void Snake::Draw() {
    float hx = body[0].x;
    float hy = body[0].y;
    DrawTexture(head, offset + hx * cellSize, offset + hy * cellSize, WHITE);

    for (unsigned int i = 1; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;
        DrawTexture(tail, offset + x * cellSize, offset + y * cellSize, WHITE);
    }
}

void Snake::Update() {
    Vector2 newHead = Vector2Add(body[0], direction);

    // Wrap-Around-Logik
    if (newHead.x < 0) newHead.x = cellCount - 1;
    if (newHead.x >= cellCount) newHead.x = 0;
    if (newHead.y < 0) newHead.y = cellCount - 1;
    if (newHead.y >= cellCount) newHead.y = 0;

    if (addSegment) {
        body.push_front(newHead);
        addSegment = false;
    } else {
        body.push_front(newHead);
        body.pop_back();
    }
}

void Snake::reset() {
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}
