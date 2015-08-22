//
//  CBody.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__CBody__
#define __Seventh__CBody__

#include <stdio.h>

#include "Define.h"


class CBody {
    
public:
    CBody(Box box);
    
    float velX, velY;
    
    int getX();
    int getY();
    int getW();
    int getH();
    
protected:
    Box _box;
    
};

#endif /* defined(__Seventh__CBody__) */
