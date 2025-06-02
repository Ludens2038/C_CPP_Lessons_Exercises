#include <iostream>
#include "raylib.h"
#include "deque" // for snake body
#include "raymath.h"

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool ElementInDeque(Vector2 element, deque<Vector2> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}

// food Class
class Food {
public:
    Vector2 position;
    Texture2D texture;

    Food(deque<Vector2> snakeBody) {
        Image image = LoadImage("./assets/burger.png");
        ImageResize(&image, 25, 25);
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = generateRandomPos(snakeBody);
    }

    ~Food() {
        UnloadTexture(texture);
    }

    void Draw() {
        DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
    }

    Vector2 generateRandomCell() {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }

    Vector2 generateRandomPos(deque<Vector2> snakeBody) {
        Vector2 position = generateRandomCell();
        while (ElementInDeque(position, snakeBody)) {
            position = generateRandomCell();
        }
        return position;
    }
};

// end food Class

// snake Class
class Snake {
public:
    Texture2D texture;
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;

    void Draw() {
        for (unsigned int i = 0; i < body.size(); i++) {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{
                offset + x * cellSize, offset + y * cellSize, (float) cellSize, (float) cellSize
            };
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update() {
        if (addSegment == true) {
            body.push_front(Vector2Add(body[0], direction));
            addSegment = false;
        } else {
            body.push_front(Vector2Add(body[0], direction));
            body.pop_back();
        }
    }

    void reset() {
        body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        direction = {1, 0};
    }
};

// end snake Class

// Game Class
class Game {
public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;
    Sound eatSound;
    Sound wallSound;

    Game() {
        InitAudioDevice();
        eatSound = LoadSound("./assets/crunchybite.ogg");
        wallSound = LoadSound("./assets/die1.mp3");
    }

    ~Game() {
        UnloadSound(eatSound);
        UnloadSound(wallSound);
        CloseAudioDevice();
    }

    void Draw() {
        food.Draw();
        snake.Draw();
    }

    void Update() {
        if (running) {
            snake.Update();
            checkCollisionWithFood();
            checkColisionWithEdges();
            checkCollisionWithTail();
        }
    }

    void checkCollisionWithFood() {
        if (Vector2Equals(snake.body[0], food.position)) {
            food.position = food.generateRandomPos(snake.body);
            snake.addSegment = true;
            score++;
            PlaySound(eatSound);
        }
    }

    void checkColisionWithEdges() {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
            GameOver();
        }
    }

    void checkCollisionWithTail() {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (ElementInDeque(snake.body[0], headlessBody)) {
            GameOver();
        }
    }

    void GameOver() {
        snake.reset();
        food.position = food.generateRandomPos(snake.body);
        running = false;
        score = 0;
        PlaySound(wallSound);
    }
};

// end Game Class

int main() {
    cout << "Starting the game" << endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Snake42");

    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false) {
        BeginDrawing();

        if (eventTriggered(0.2)) {
            game.Update();
        }

        // USER_INPUT for movement
        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
            game.snake.direction = {0, -1};
            game.running = true;
        } else if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
            game.snake.direction = {0, 1};
            game.running = true;
        } else if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
            game.snake.direction = {-1, 0};
            game.running = true;
        } else if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
            game.snake.direction = {1, 0};
            game.running = true;
        }

        ClearBackground(green);
        DrawRectangleLinesEx(
            Rectangle{
                (float) offset - 5,
                (float) offset - 5,
                (float) cellSize * cellCount + 10,
                (float) cellSize * cellCount + 10
            },
            5,
            darkGreen
        );
        DrawText("Snake42", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("Score: %i", game.score), offset - 10, offset + cellSize * cellCount + 10, 40, darkGreen);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
