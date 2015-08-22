//
//  CEntity.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__CEntity__
#define __Seventh__CEntity__

#include <stdio.h>
#include <SDL2/SDL.h>

#include "Define.h"
#include "CBody.h"

class CEntity {
    
public:
    CEntity(Box box, Color color);
    
    void onLoop();
    void onRender();
    
    void addProperty(EntityProperties property);
    void toggleProperty(EntityProperties property);
    void removeProperty(EntityProperties property);
    bool hasProperty(EntityProperties property);
    
    CBody body;
    
private:
    void _move();
    bool _collision(Box box);
    bool _coordinateCollision(Box box);
    
    int _entityProperties; /* See EntityProperties */
    
};

#endif /* defined(__Seventh__CEntity__) */
