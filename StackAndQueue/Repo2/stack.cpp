//
//  stack.cpp
//  Repo2
//
//  Created by 이신육 on 2019/10/10.
//  Copyright © 2019 이신육. All rights reserved.
//
#include <iostream>
#include "stack.hpp"
using namespace std;
template <class T>
Stack<T>::Stack() {
    capacity = 4;
    top = -1;
    stack = new T[capacity];
}

template <class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity){
    if( capacity < 1) throw "Stack capacity must be > 0";
    stack = new T[capacity];
    top = -1; // stack이 비어있다.
}

template <class T>
void Stack<T>::push(const T& x){ //값을 넣어준다.
    if(top == capacity - 1){ // 배열의 크기를 두배로 확장한다.
        capacity *= 2;
        T *temp = new T[capacity];
        for(int i = 0; i < top; i++){
            temp[i] = stack[i];
        }
        delete[] stack;
        stack = temp;
    }
    stack[++top] = x;
}

template <class T>
T* Stack<T>::pop(T &x){ //stack에서 톱 원소를 삭제한다.
    if(top == -1) return 0; // 빈상태 >> null로 반환
     //삭제되는 값을 x에 저장한다.
    x = stack[top--];
    return &x; // x의 주소를 반환한다.
    // 반환하는 값이 Null이면 스택이 비어있다는 것이고, Null이 아니면 반환값을 주소로 갖는 변수에 삭제하고자 하는 값이 할당되어있다.
}

template <class T>
bool Stack<T>::isEmpty(){
    if(top == -1){
        return true; //비어있다.
    } else {
        return false; // 비어있지않다.
    }
}

template <class T>
T* Stack<T>::printTop() {
    if(stack[top]){
        return &stack[top];
    } else {
        return 0;
    }
}

template <class T>
int Stack<T>::size() {
    return top;
}

template <class T>
void Stack<T>::print() {
    for(int i = top; i > -1; i--){
        cout << stack[i] << " ";
    }
}
