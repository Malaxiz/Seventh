//
//  CBody.cpp
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "CBody.h"


CBody::CBody(Box box) : _box(box) {
    
}

int CBody::getX() {
    return _box.x;
}

int CBody::getY() {
    return _box.y;
}

int CBody::getW() {
    return _box.w;
}

int CBody::getH() {
    return _box.h;
}
