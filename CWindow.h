//
//  CWindow.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__CWindow__
#define __Seventh__CWindow__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

class CWindow {
    
public:
    CWindow();
    
    int onInit(std::string title, int width, int height);
    int newWindow(std::string title, int width, int height);
    void setTitle(std::string title);
    void onCleanup();
    
    int getWidth();
    int getHeight();
    
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
    int _screenHeight, _screenWidth;
    
};

#endif /* defined(__Seventh__CWindow__) */
