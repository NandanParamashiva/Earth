//
//  maxKandNegK.cpp
//  earth
//
//  Created by Nandan Paramashiva on 2/16/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

#include "maxKandNegK.hpp"
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int findMaxK(vector<int> arr) {
    unordered_set<int> db;
    int ans=INT_MIN;
    for(auto n : arr){
        if(db.find(-1*n)!=db.end()){
            db.insert(n);
            continue;
        }
        // neg of num exists in db;
        ans = max(ans, abs(n));
    }
    return ans;
}


