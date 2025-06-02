#include "header-files/game.h"

#include "raymath.h"
#include "header-files/utils.h"

Game::Game() : snake(), food(snake.body), running(true), score(0) {
    InitAudioDevice();
    eatSound = LoadSound("./assets/crunchybite.ogg");
    wallSound = LoadSound("./assets/die1.mp3");
}

Game::~Game() {
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::Update() {
    if (running) {
        snake.Update();
        checkCollisionWithFood();
        checkColisionWithEdges();
        checkCollisionWithTail();
    }
}

void Game::checkCollisionWithFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        food.position = food.generateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
        PlaySound(eatSound);
    }
}

void Game::checkColisionWithEdges() {
    if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
        GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
        GameOver();
    }
}

void Game::checkCollisionWithTail() {
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody)) {
        GameOver();
    }
}

void Game::GameOver() {
    snake.reset();
    food.position = food.generateRandomPos(snake.body);
    running = false;
    score = 0;
    PlaySound(wallSound);
}
