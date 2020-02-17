//
//  airlineReservationMSFT.cpp
//  earth
//
//  Created by Nandan Paramashiva on 2/16/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

#include "airlineReservationMSFT.hpp"
#include "stringUtility.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int getReservationCount(int n, string s) {
    
    // n is rows
    vector<string> rsvs; // reservations
    
    // utility from stringUtility.hpp
    split<vector<string>>(s, rsvs, ' ');
    
    // seats as a database
    unordered_map<int, unordered_set<char>> seats;
    // initialize data base
    unordered_set<char> tmp;
    for(int i=0; i<n ; i++){
        seats[i]=tmp;
    }
    
    // build the database.
    for(auto r:rsvs){
        
        int row=0;
        string column;
        splitNumAndString(r, row, column);
        char c = column[0];
        row--; // 0 based
        seats[row].insert(c);
    }
    
    // database is built
    // walk the possibilities of placement of families.
    int count = 0;
    for(int i=0; i<n ; i++){
        auto& c = seats[i];
        
        // case 1 [B, C, D, E]
        if(c.find('B')==c.end() && c.find('C')==c.end() &&
           c.find('D')==c.end() && c.find('E')==c.end()){
            // we can place a family here.
            count++;
            c.insert('B');
            c.insert('C');
            c.insert('D');
            c.insert('E');
        }

        // case 2 [D, E, F, G]
        if(c.find('D')==c.end() && c.find('E')==c.end() &&
           c.find('F')==c.end() && c.find('G')==c.end()){
            // we can place a family here.
            count++;
            c.insert('D');
            c.insert('E');
            c.insert('F');
            c.insert('G');
        }
        
        // case 3 [F, G, H, J]
        if(c.find('F')==c.end() && c.find('G')==c.end() &&
           c.find('H')==c.end() && c.find('J')==c.end()){
            // we can place a family here.
            count++;
            c.insert('F');
            c.insert('G');
            c.insert('H');
            c.insert('J');
        }
    }
    return count;
}

void airlineReservationMSFTEntry(){
    std::cout << "test airlineReservationMSFTEntry" << std::endl;
    string s = "1A 2F 1C";
    int size = 2;
    int res = getReservationCount(size, s);
    std::cout << "result=" << res << std::endl;
}


