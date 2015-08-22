//
//  SMouse.cpp
//  Third
//
//  Created by Didrik Munther on 16/04/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "SMouse.h"
#include <SDL2/SDL.h>

int SMouse::absoluteMouseX() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x;
}

int SMouse::absoluteMouseY() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return y;
}

//int SMouse::relativeMouseX(CCamera* camera) {
//    int x, y;
//    SDL_GetMouseState(&x, &y);
//    return x + camera->offsetX();
//}
//
//int SMouse::relativeMouseY(CCamera* camera) {
//    int x, y;
//    SDL_GetMouseState(&x, &y);
//    return y + camera->offsetY();
//}

bool SMouse::leftMouseButtonPressed() {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
}

bool SMouse::rightMouseButtonPressed() {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT);
}