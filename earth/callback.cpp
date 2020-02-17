//
//  callback.cpp
//  earth
//
//  Created by Nandan Paramashiva on 1/30/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

// Understanding the call back mechanism

#include "callback.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

//
// from http://www.cplusplus.com/reference/functional/function/function/
// std::function
//

// a function:
int half(int x) {return x/2;}

// a function object class:
struct third_t {
    int operator()(int x) {return x/3;}
};

// a class with data members:
struct MyValue {
    int value;
    int fifth() {return value/5;}
};

void xyz(){
    
    std::function<int(int)> fn1 = half;                    // function
    std::function<int(int)> fn2 = &half;                   // function pointer
    std::function<int(int)> fn3 = third_t();               // function object
    std::function<int(int)> fn4 = [](int x){return x/4;};  // lambda expression
    std::function<int(int)> fn5 = std::negate<int>();      // standard function object
    
    std::cout << "fn1(60): " << fn1(60) << '\n';
    std::cout << "fn2(60): " << fn2(60) << '\n';
    std::cout << "fn3(60): " << fn3(60) << '\n';
    std::cout << "fn4(60): " << fn4(60) << '\n';
    std::cout << "fn5(60): " << fn5(60) << '\n';
    
    // stuff with members:
    std::function<int(MyValue&)> value = &MyValue::value;  // pointer to data member
    std::function<int(MyValue&)> fifth = &MyValue::fifth;  // pointer to member function
    
    MyValue sixty {60};
    
    std::cout << "value(sixty): " << value(sixty) << '\n';
    std::cout << "fifth(sixty): " << fifth(sixty) << '\n';
}


//
// Method 2
// std::function class
//
int sum(int a, int b){
    return a+b;
}

void simpleCallback2(int a, int b, std::function<int(int, int)> func) {
    std::cout << "simpleCallback2: " << func(a, b) << std::endl;
}
bool lessThan(int a, int b){
    return a<b;
}
bool greaterThan(int a, int b){
    return a>b;
}
bool comparePair(std::pair<int, int> a, std::pair<int, int> b, std::function<bool(int, int)> funcObj){
    int x = a.second;
    int y = b.second;
    return funcObj(x, y);
}
// function example
#include <iostream>     // std::cout
#include <functional>   // std::function, std::negate



void callback2(){
    simpleCallback2(4, 5, sum);
    
    std::pair<int, int> a(6,7);
    std::pair<int, int> b(9,11);
    //std::function<bool(int, int)> f = greaterThan;
    //std::function<bool(int, int)> f = lessThan; // normal function name - works
    std::function<bool(int, int)> f = std::less<int>(); // template class name - works
    if(comparePair(a, b, f)){
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    
    xyz();
}


//
// Method 1
// using function pointers.
//

class keyFunction {
public:
    void keyBind(char ch, void (*funcPtr)(int)){
        db[ch] = funcPtr;
    }
    
    void keyPressed(char ch, int degree){
        void (*funcptr)(int);
        funcptr = db[ch];
        funcptr(degree);
    }
private:
    std::unordered_map<char, void(*)(int)> db;
};

void jump(int degree){
    std::cout << "jump:" << degree << std::endl;
}

void slide(int degree){
    std::cout << "slide:" << degree << std::endl;
}

int modOp(int i){
    return i%100;
}

void simpleCallback(std::string s, int i, int (*fptr)(int i)){
    std::cout << "simpleCallback of " << s;
    std::cout << " result " << fptr(i) << std::endl;
}

void callback1() {
    
    //////
    // smart pointers:
    std::weak_ptr<keyFunction> wPtr;
    {
    std::shared_ptr<keyFunction> Sptr = std::make_shared<keyFunction>();
    Sptr->keyBind('1', &slide);
        
    wPtr = Sptr;
    wPtr.lock()->keyBind('2', &jump);
        std::cout<< "count:"<< wPtr.use_count();
        
        std::unique_ptr<keyFunction> uPtr(new keyFunction());
        // std::unique_ptr<keyFunction> ttmp = uPtr; // << compilation error because we can not copy unique ptrs.
    }
    
    if(wPtr.expired()){
        if(std::shared_ptr<keyFunction> tmp= wPtr.lock()){
            tmp->keyBind('1', &slide);
        } else {
            std::cout << "ref count 0" << std::endl;
        }
    }
    
    //////
    
    
    std::cout << "callback1" << std::endl;
#if 0
    keyFunction k;
    
    k.keyBind('1', &slide);
    k.keyBind('2', &jump);
    
    k.keyPressed('1', 12);
    k.keyPressed('2', 104);
    
    
    simpleCallback("modOp", 108, &modOp);
#endif
    return;
}

void callbackEntry(){
    std::cout << "callbackEntry" << std::endl;
    callback1();
    //callback2();
    
}
