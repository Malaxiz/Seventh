//
//  CLocator.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__CLocator__
#define __Seventh__CLocator__

#include <stdio.h>
#include <unordered_map>

#include "SService.h"
#include "SFile.h"


class CLocator {
    
public:
    CLocator();
    
    static void provideService(SService* service);
    template<typename T>
    static T* getService() {
        if(_services.count(&typeid(T)) == 0)
        {
            provideService(new T()); // Create new service if it does not exist
            SFile* fileService;
            if(&typeid(T) == &typeid(SFile))
                fileService = static_cast<SFile*>(_services[&typeid(SFile)]);
            else
                fileService = getService<SFile>();
            fileService->log(LogType::WARNING, "Service of type \"", typeid(T).name(), "\" didn't exist, so one was created.");
            
        }
        
        return static_cast<T*>(_services[&typeid(T)]);
    }
    
    static void clearServices();
    
private:
    static std::unordered_map<const std::type_info*, SService*> _services;
    
};

#endif /* defined(__Seventh__CLocator__) */
