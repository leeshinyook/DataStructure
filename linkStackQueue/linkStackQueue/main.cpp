//
//  main.cpp
//  Queue
//
//  Created by 이신육 on 2019/10/14.
//  Copyright © 2019 이신육. All rights reserved.
//
#include <iostream>
using namespace std;

void PrintTable() {
    cout << "\t" << "---- 메뉴 ----" << "\n" << "1.스택에 삽입" << "\t" << "2.큐에 삽입" << "\n";
    cout << "3.스택에서 삭제" << "\t" << "4.큐에서 삭제" << "\n" << "5 .스택 내용 보기" << "\t" << "6.큐 내용 보기"<<"\n";
};


class linkedstack;
class chainnode
{
   friend class linkedstack;
   friend class linkedqueue;
private:
   int data;
   chainnode *link;
public:
   chainnode(int element = 0, chainnode* next = 0) //생성자
   {
      data = element; link = next;
   }
};
class linkedstack
{
   chainnode *top;
public:
   linkedstack() { top = 0; }//생성자
   void push(const int&);//삽입함수
   int* pop(int&);//삭제함수
   void showstack();
};
void linkedstack::push(const int& e)//삽입
{
   top = new chainnode(e, top);
}
int* linkedstack::pop(int& x)//삭제
{//스택에서 톱 노드를 삭제하고 값을 x에 저장한 후에 x의 주소를 반환
   if (top == 0) return 0;
   chainnode * delnode = top;
   x = top -> data;
   top = top -> link;
   delete delnode;
   return &x;
}
void linkedstack::showstack()
{
    
   chainnode * temp = top;
    for(;top;){
        
      cout << temp -> data;
       temp = temp -> link;
   }
}
class linkedqueue
{
   chainnode * front, *rear;
public:
   linkedqueue() { front = 0; rear = 0; }
   void push(const int & e);
   int* pop(int & retvalue);
   void showqueue();
};
void linkedqueue::push(const int & e)//삽입
{
   if (front == 0) front = rear = new chainnode(e, 0);//공백 큐
   else rear = rear->link = new chainnode(e, 0);//노드를 삽입하고 rear를 수정함
}
int * linkedqueue::pop(int & retvalue)//삭제
{//큐에 있는 첫번째 노드를 제거하고 그 데이터의 포인터를 반환
   if (front == 0) return 0;
   chainnode * delnode = front;
   retvalue = front->data;
   front = front->link;
   delete delnode;
   return &retvalue;
}
void linkedqueue::showqueue()
{
  
    chainnode* temp = front;
    while(temp){
        cout << temp ->data;
        temp = temp -> link;
    }
    
}
int main()
{
   int num, n, x,v;
   linkedstack a;
   linkedqueue b;
   while (1)
   {
       PrintTable();
      cin >> num;//메뉴번호를 입력받음
      if (num == 1)//스택에 삽입
      {
         cin >> n; a.push(n);//스택에 넣을 데이터입력
      }
      else if (num == 2)//큐에 삽입
      {
         cin >> n; b.push(n);//큐에 넣을 데이터입력
      }
      else if (num == 3)//스택에서 삭제
         a.pop(x);
      else if (num == 4)//큐에서 삭제
         b.pop(v);
      else if (num == 5)//스택 내용
      {
         a.showstack(); break;
      }
      else if (num == 6)
      {
         b.showqueue(); break;
      }
   }
}

