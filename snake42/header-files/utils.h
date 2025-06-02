#pragma once
#include "raylib.h"
#include <deque>

extern const int cellSize;
extern const int cellCount;
extern const int offset;

extern const Color green;
extern const Color darkGreen;

bool eventTriggered(double interval);
bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
