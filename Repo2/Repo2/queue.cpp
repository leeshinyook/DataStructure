//
//  queue.cpp
//  Repo2
//
//  Created by 이신육 on 2019/10/10.
//  Copyright © 2019 이신육. All rights reserved.
//
#include <iostream>
#include "queue.hpp"
using namespace std;
template <class T>
Queue<T>::Queue(int queueCapacity): capacity(queueCapacity){ // 생성자
    if(capacity < 1) throw "Queue capacity must be > 0";
    queue = new T[capacity];
    front = rear = -1;
}
template <class T>
void Queue<T>::Push(const T &x){
    if(rear == capacity - 1){
        capacity *= 2;
        T *temp = new T[capacity]; //새로운 배열
        for(int i = 0; i < rear; i++)
        {
            temp[i] = queue[i];
        }
        delete [] queue; //그 전 메모리를 반환한다.
        queue = temp;
    } // 큐가 full이므로 크기를 두배로 늘려준다.
    queue[++rear] = x;
}

template <class T>
T* Queue<T>::Pop(){
    if(front == rear) return 0; // queue is Empty.
    T x  = queue[front++];
    return &x;
}

template <class T>
bool Queue<T>::isEmpty() {
    if(front == rear) return 1;
    else return 0;
}

template <class T>
void Queue<T>::print() {
    for(int i = front; i < rear; i++) {
        cout << queue[i] << " ";
    }
}
