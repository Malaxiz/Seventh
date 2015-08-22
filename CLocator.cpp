//
//  CLocator.cpp
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "CLocator.h"


std::unordered_map<const std::type_info*, SService*> CLocator::_services;

CLocator::CLocator() {

}

void CLocator::provideService(SService *service) {
    if(_services.count(&typeid(*service)) != 0)
        delete _services[&typeid(*service)];
    _services[&typeid(*service)] = service;
}

void CLocator::clearServices() {
    
    getService<SFile>()->log(LogType::ALERT, "Unloading services.");
    
    for(auto &i: _services) {
        delete i.second;
    }
    _services.clear();
}