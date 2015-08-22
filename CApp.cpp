//
//  CApp.cpp
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "CApp.h"
#include "CLocator.h"
#include "SFile.h"
#include "SMouse.h"
#ifdef __APPLE__
 #include "CoreFoundation/CoreFoundation.h"
 #include "ResourcePath.hpp"
#endif


CApp::CApp() {
    _isRunning = true;
    
    _lastTime   =
    _timer      = SDL_GetTicks();
    
    _ns = 1000.0f / 60.0;
    
    _delta      =
    _frames     =
    _updates    = 0;
    
}

int CApp::onExecute() {
    
    if(_onInit())
        return -1;
    
    CLocator::getService<SFile>()->log(LogType::ALERT, "Starting game.");
    
    while(_isRunning) {
        while(SDL_PollEvent(&event))
            _onEvent(&event);
        
        float now = SDL_GetTicks();
        _delta += (now - _lastTime) / _ns;
        
        while(_delta >= 1) {
            _onLoop();
            ++_updates;
            --_delta;
        }
        
        _onRender();
        ++_frames;
        
        if(SDL_GetTicks() - _timer > 1000) { // 1 second timer
            _timer += 1000;
            _updates    =
            _frames     = 0;
        }
        
    }
    
    CLocator::getService<SFile>()->log(LogType::ALERT, "Ending game.");
    
    return _onCleanup();
}

int CApp::_onInit() {
    
    //CLocator::provideService(new SFile());
    //CLocator::provideService(new SMouse());
    
    CLocator::getService<SFile>()->log(LogType::ALERT, "Initializing game...");
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        CLocator::getService<SFile>()->log(LogType::ERROR, "SDL_Init failed: ", SDL_GetError());
        return -1;
    }
    
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        CLocator::getService<SFile>()->log(LogType::ERROR, "IMG_Init failed: ", SDL_GetError());
        return -1;
    }
    
    if(TTF_Init() != 0) {
        CLocator::getService<SFile>()->log(LogType::ERROR, "TTF_Init failed: ", SDL_GetError());
        return -1;
    }
    
    if(instance.window.onInit("Third game simulation", 1024, 720))
        return -1;
    
    srand((Uint16)time(nullptr));
    
    CLocator::getService<SFile>()->log(LogType::ALERT, "Initializing successful.");
    
    return 0;
}

void CApp::_initRelativePaths() {
    // ----------------------------------------------------------------------------
    // This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
    #ifdef __APPLE__
        CFBundleRef mainBundle = CFBundleGetMainBundle();
        CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
        char path[PATH_MAX];
        if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
        {
            // error!
        }
        CFRelease(resourcesURL);
        
        chdir(path);
        CLocator::getService<SFile>()->log(LogType::ALERT, "Current Path: ", path);
    #endif
    // ----------------------------------------------------------------------------
}

void CApp::_onLoop() {
    
}

void CApp::_onRender() {
    
    SDL_SetRenderDrawColor(instance.window.getRenderer(), 240, 240, 240, 255);
    SDL_RenderClear(instance.window.getRenderer());
    
    SDL_RenderPresent(instance.window.getRenderer());
    
}

void CApp::_onEvent(SDL_Event* event) {
    
    switch(event->type) {
            
        case SDL_QUIT:
            _isRunning = false;
            return;
        
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym) {
                case SDLK_ESCAPE:
                    _isRunning = false;
                    break;
            }
            break;
            
        case SDL_KEYUP:
            switch(event->key.keysym.sym) {
                    
            }
            break;
    }
    
}

int CApp::_onCleanup() {
    
    CLocator::getService<SFile>()->log(LogType::ALERT, "Good bye.");
    CLocator::clearServices();
    
    return 0;
}