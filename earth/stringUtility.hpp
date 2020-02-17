//
//  stringUtility.hpp
//  earth
//
//  Created by Nandan Paramashiva on 2/16/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

#ifndef stringUtility_hpp
#define stringUtility_hpp

#include <stdio.h>
#include <string>
#include <vector>

void stringUtilityEntry();

template <class Container>
void split(const std::string& str, Container& cont, char delim);

void splitNumAndString(std::string input, int& num, std::string& remaining);

#endif /* stringUtility_hpp */
