#include "header-files/food.h"
#include "header-files/utils.h"

Food::Food(std::deque<Vector2> snakeBody) {
    Image image = LoadImage("assets/bier.png");
    ImageResize(&image, 35, 35);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = generateRandomPos(snakeBody);
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::Draw() {
    DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

Vector2 Food::generateRandomCell() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}

Vector2 Food::generateRandomPos(std::deque<Vector2> snakeBody) {
    Vector2 pos = generateRandomCell();
    while (ElementInDeque(pos, snakeBody)) {
        pos = generateRandomCell();
    }
    return pos;
}
