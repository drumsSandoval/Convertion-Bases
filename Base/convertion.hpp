//
//  convertion.hpp
//  Base
//
//  Created by Oscar Sandoval on 02/02/20.
//  Copyright © 2020 Oscar Sandoval. All rights reserved.
//

#ifndef convertion_h
#define convertion_h
#include <exception>
#include <iostream>
class Convertion {
private:
    std::string number;
    int entryBase;
    int exitBase;
    int toBase10();
    int getValue(std::string);
public:
    Convertion();
    void setInitialBase(std::string);
    void setNumber(std::string);
    void setExitBase(std::string);
    std::string process();
};

#endif /* convertion_h */
