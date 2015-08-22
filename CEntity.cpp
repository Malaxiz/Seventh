//
//  CEntity.cpp
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "CEntity.h"
#include "CBody.h"


CEntity::CEntity(Box box, Color color) : body(box) {
}

void CEntity::addProperty(EntityProperties property) {
    if(!hasProperty(property)) toggleProperty(property);
}

void CEntity::toggleProperty(EntityProperties property) {
    _entityProperties ^= (int)property;
}

void CEntity::removeProperty(EntityProperties property) {
    if(hasProperty(property)) toggleProperty(property);
}

bool CEntity::hasProperty(EntityProperties property) {
    return _entityProperties & property;
}