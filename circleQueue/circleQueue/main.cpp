//
//  main.cpp
//  circleQueue
//
//  Created by 이신육 on 2019/10/22.
//  Copyright © 2019 이신육. All rights reserved.
//



#include <iostream>
using namespace std;
class CircleQueue {
private:
    int capacity;
    int front, rear;
    int * queue;
public:
    CircleQueue();
    void Pop();
    void Push(const int &x);
    void Print();
};

CircleQueue::CircleQueue() {
    capacity = 4;
    front = rear = 0;
    queue = new int[capacity];
}

void CircleQueue::Push(const int &x) {
    if((rear + 1) % capacity == front){
        capacity *= 2;
        int * temp = new int[capacity];
        for(int i = front; i < rear; i++){
            temp[i] = queue[i];
        }
        delete [] queue;
        queue = temp;
    }
    queue[rear] = x;
    rear = (rear + 1) % capacity;
}
void CircleQueue::Pop() {
    if(front == rear) return;
    front = (front + 1) % capacity;
}
void CircleQueue::Print() {
    for(int i = front; i < rear; i++){
        cout << queue[i] << endl;
    }
}

int main() {
    CircleQueue myQueue;
    myQueue.Push(30);
    myQueue.Push(20);
    myQueue.Push(10);
    myQueue.Print();

    return 0;
    
}
