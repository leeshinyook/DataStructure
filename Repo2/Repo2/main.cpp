//
//  main.cpp
//  Repo2
//
//  Created by 이신육 on 2019/10/10.
//  Copyright © 2019 이신육. All rights reserved.
//

#include <iostream>
#include "queue.cpp" // queue 분리
#include "stack.cpp" // stack 분리
using namespace std;

void printFormat() {
    cout << "\t\t" <<"--- 메뉴 ---" << endl;
    cout << "1. 스택에 삽입 \t\t" << "2. 큐에 삽입" << endl;
    cout << "3. 스택에서 삭제\t" << "4. 큐에서 삭제" << endl;
    cout << "5. 스택내용 보기\t" << "6. 큐내용 보기" << endl;
    cout << "7. 끝내기" << endl;
}
int main() {
    int testNum = 0;
    int num;
    Stack<int> myStack;
    Queue<int> myQueue(4);
    while(1) {
        printFormat();
        cin >> testNum;
        if(testNum == 1){ // 스택에 삽입
            cin >> num;
            myStack.push(num);
        } else if (testNum == 2){ // 큐에 삽입
            cin >> num;
            myQueue.Push(num);
        } else if (testNum == 3){ // 스택에서 삭제
            if(myStack.isEmpty()){
                cout << "스택이 비었습니다." << endl;
            } else myStack.pop(num);
        } else if (testNum == 4){ // 큐에서 삭제
            if(myQueue.isEmpty()){
                cout << "큐가 비었습니다." << endl;
            } else myQueue.Pop();
        } else if (testNum == 5){ // 스택내용 보기
            if(myStack.isEmpty()){
                cout << "스택이 비었습니다." << endl;
            } else myStack.print();
        } else if (testNum == 6){ // 큐내용 보기
            if(myQueue.isEmpty()){
                cout << "큐가 비었습니다." << endl;
            } else myQueue.print();
        } else if (testNum == 7) break; //끝내기
    }
    
    
    
    return 0;
}
