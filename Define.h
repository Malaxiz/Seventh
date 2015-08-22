//
//  Define.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__Define__
#define __Seventh__Define__

#include <stdio.h>


const char LOG_FILE[] = "debug.log";

struct Box {
    int x, y;
    int w, h;
};

struct Color {
    int r, b, g;
    int a;
};

enum EntityProperties {
    NONE        = 1 << 0,
    STATIC      = 1 << 1,
    COLLIDABLE  = 1 << 2,
    VISIBLE     = 1 << 3
};

#endif