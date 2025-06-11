#include <iostream>
#include "raylib.h"
#include "header-files/game.h"
#include "header-files/utils.h"
#include <queue>

int main() {

    bool pause = false;
    double moveInterval = 0.2;

    InitAudioDevice();
    Music bgMusic = LoadMusicStream("./assets/gameMusic.mp3");
    SetMusicVolume(bgMusic, 0.2f);
    PlayMusicStream(bgMusic);

    std::queue<Vector2> directionQueue;

    std::cout << "Starting the game" << std::endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Snake42");

    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose()) {
        BeginDrawing();
        UpdateMusicStream(bgMusic);

        // Pause umschalten
        if (IsKeyPressed(KEY_P)) {
            pause = !pause;
        }

        if (!pause && eventTriggered(moveInterval)) {
            if (!directionQueue.empty()) {
                game.snake.direction = directionQueue.front();
                directionQueue.pop();
            }
            game.Update();
        }

        ClearBackground(green);

        // Spielfeld-Rand
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

        // Titel & Score
        DrawText("Snake42", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("Score: %i", game.score), offset - 10, offset + cellSize * cellCount + 10, 40, darkGreen);

        game.Draw();

        // USER_INPUT for movement
        if (!pause) {
            Vector2 lastDir = game.snake.direction;
            if (!directionQueue.empty())
                lastDir = directionQueue.back();

            if (IsKeyPressed(KEY_UP) && lastDir.y != 1) {
                directionQueue.push({0, -1});
                lastDir = {0, -1};
                game.running = true; // Spiel starten
            }
            if (IsKeyPressed(KEY_DOWN) && lastDir.y != -1) {
                directionQueue.push({0, 1});
                lastDir = {0, 1};
                game.running = true;
            }
            if (IsKeyPressed(KEY_LEFT) && lastDir.x != 1) {
                directionQueue.push({-1, 0});
                lastDir = {-1, 0};
                game.running = true;
            }
            if (IsKeyPressed(KEY_RIGHT) && lastDir.x != -1) {
                directionQueue.push({1, 0});
                lastDir = {1, 0};
                game.running = true;
            }
        }

        // Pause-Anzeige zentrieren
        if (pause) {
            const char* pauseText = "PAUSE";
            int fontSize = 60;
            int textWidth = MeasureText(pauseText, fontSize);
            DrawText(pauseText, (GetScreenWidth() - textWidth) / 2, GetScreenHeight() / 2 - fontSize, fontSize, RED);
        }

        EndDrawing();
    }

    UnloadMusicStream(bgMusic);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
