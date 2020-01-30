//
//  callback.cpp
//  earth
//
//  Created by Nandan Paramashiva on 1/30/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "callback.h"

void someSampleCallBack(){
    std::cout << "Hey" << std::endl;
}

int callbackEntry(){
    
    std::cout << "to learn callback mechanism" << std::endl;
    someSampleCallBack();
    
    return 0;
}
