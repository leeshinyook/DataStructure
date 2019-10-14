//
//  stack.hpp
//  Repo2
//
//  Created by 이신육 on 2019/10/10.
//  Copyright © 2019 이신육. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
template <class T>
class Stack {
public:
    Stack();
    Stack(int);
    T* pop(T &x);
    T* printTop(); // 스택의 최상위 정수를 출력한다.
    int size();
    void print();
    void push(const T&);
    bool isEmpty();
private:
    T* stack; // 스택 원소를 위한 배열
    int top; // 톱 원소의 위치
    int capacity; // 스택 배열의 크기
};
#endif /* stack_hpp */
