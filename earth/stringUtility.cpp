//
//  stringUtility.cpp
//  earth
//
//  Created by Nandan Paramashiva on 2/16/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

#include "stringUtility.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////
//
// Example:
// input="231A"  ; num=231; remaining="A"
//
// input="593AB" ; num=593; remaining="AB"
//
void splitNumAndString(string input, int& num, string& remaining) {
    int i = 0;
    while(i<input.size() && isdigit(input[i])){
        i++;
    }
    if(i==0) return;
    num = stoi(input.substr(0, i));
    remaining = input.substr(i, input.size()-i);
}
          
/////////////////////////////////////////////////////////////////
//
// Split in c++
//

#if 0
#include <boost/algorithm/string.hpp>

//
// Method 1
// boost split and is_any_of
//
void split(string& input, vector<string>& result, const string delimiter=" "){
  boost::split(result, input, boost::is_any_of(delimiter));
}

//
// Method 2
// using boost split and lambda
//
void split(string& input, vector<string>& result){
  boost::split(result, input, [](char c){return c == ' ';});
}
#endif

//
// Method 3
// using find
//
#include <string>
#include <algorithm>
#include <iterator>
          
template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}
  
/////////////////////////////////////////////////////////////////


void stringUtilityEntry(){
    
    std::cout << "test string utility" << std::endl;
    bool testSplitNumAndString = false;
    bool testSplit=true;
    //
    // test splitNumAndString
    //
    if(testSplitNumAndString)
    {
        string s1 = "234LMN";
        string str;
        int num;
        splitNumAndString(s1, num, str);
        cout << " num="<<num<<" str="<< str << endl;
        char ch = str[0];
        cout << " num="<<num<<" ch="<< ch << endl;
    }
    
    //
    // test split
    //
    if(testSplit)
    {
        cout << "\nTC:" << endl;
        string s1("this is a test string");
        vector<string> res1;
        split<vector<string>>(s1, res1);
        for(auto s:res1){
            cout << s << std::endl;
        }
        
        cout << "\nTC:" << endl;
        string s2("1A 2B 3H 5G");
        vector<string> res2;
        split<vector<string>>(s2, res2, ' ');
        for(auto s:res2){
            cout << s << std::endl;
            string str;
            int num;
            splitNumAndString(s, num, str);
            cout << "num="<<num<<" str="<< str << endl;
        }
    }
    
}
