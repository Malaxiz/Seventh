//
//  SMouse.h
//  Third
//
//  Created by Didrik Munther on 16/04/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Third__SMouse__
#define __Third__SMouse__

#include <stdio.h>

#include "SService.h"
//#include "CCamera.h"


class SMouse : public SService {
    
    int absoluteMouseX();
    int absoluteMouseY();
    
    //int relativeMouseX(CCamera* camera);
    //int relativeMouseY(CCamera* camera);
    
    bool leftMouseButtonPressed();
    bool rightMouseButtonPressed();
    
};

#endif /* defined(__Third__SMouse__) */
