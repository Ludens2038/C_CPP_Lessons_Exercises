#include "header-files/utils.h"

#include "raymath.h"

const int cellSize = 30;
const int cellCount = 25;
const int offset = 75;

const Color green = {173, 204, 96, 255};
const Color darkGreen = {43, 51, 24, 255};

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}
