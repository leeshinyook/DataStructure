//
//  queue.hpp
//  Repo2
//
//  Created by 이신육 on 2019/10/10.
//  Copyright © 2019 이신육. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
template <class T>
class Queue {
public :
    Queue();
    Queue(int);
    void Push(const T &x);
    T* Pop();
    void print();
    bool isEmpty();
private :
    T* queue;
    int front, rear;
    int capacity;
};


#endif /* queue_hpp */
