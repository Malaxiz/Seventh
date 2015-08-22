//
//  SFile.h
//  Seventh
//
//  Created by Didrik Munther on 22/08/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __Seventh__SFile__
#define __Seventh__SFile__

#include <stdio.h>
#include <fstream>
#include <iostream>

#include "SService.h"
#include "Define.h"


enum LogType {
    SUCCESS = 0,
    ERROR,
    WARNING,
    ALERT
};

class SFile : public SService {
    
public:
    
    template<typename... T>
    void writeToFile(std::string fileName, T&&... t) {
        std::ofstream file(fileName, std::ios::app);
        _writeToFile(file, std::forward<T>(t)...);
        file.close();
    }
    
    template<typename... T>
    void log(LogType type, T&&... t) {
        
        std::string alert = "";
        
        switch(type) {
            case LogType::SUCCESS:
                alert = "[SUCCESS] ";
                break;
                
            case LogType::ERROR:
                alert = "[ERROR] ";
                break;
                
            case LogType::WARNING:
                alert = "[WARN] ";
                break;
                
            case LogType::ALERT:
                alert = "[ALERT] ";
                break;
                
            default:
                alert = "[] ";
                break;
        }
        
        _print(alert, std::forward<T>(t)..., "\n");
        writeToFile(LOG_FILE, alert, std::forward<T>(t)..., "\n");
    }
    
private:
    
    template<typename T>
    void _print(T &&t) {
        std::cout << t;
    }
    
    template<typename Head, typename... Tail>
    void _print(Head &&head, Tail&&... tail) {
        std::cout << head;
        _print(std::forward<Tail>(tail)...);
    }
    
    template<typename T>
    void _writeToFile(std::ofstream& file, T &&t) {
        file << t;
    }
    
    template<typename Head, typename... Tail>
    void _writeToFile(std::ofstream& file, Head &&head, Tail&&... tail) {
        file << head;
        _writeToFile(file, std::forward<Tail>(tail)...);
    }
    
};

#endif /* defined(__Seventh__SFile__) */
