//
//  CApp.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__CApp__
#define __Seventh__CApp__

#include <stdio.h>
#include <SDL2/SDL.h>

#include "CInstance.h"

#include <vector>


class CApp {
    
public:
    CApp();
    
    int onExecute();
    
private:
    int _onInit();      /* Main loops */
    void _onLoop();
    void _onRender();
    void _onEvent(SDL_Event* event);
    int _onCleanup();
    void _initRelativePaths();
    
    bool _isRunning;    /* Main variables */
    SDL_Event event;
    CInstance instance;
    
    float _lastTime;    /* Timer variables */
    float _timer;
    float _ns;
    float _delta;
    int _frames;
    int _updates;
    
};

#endif /* defined(__Seventh__CApp__) */
