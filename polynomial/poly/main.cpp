//
//  main.cpp
//  poly
//
//  Created by 이신육 on 22/09/2019.
//  Copyright © 2019 이신육. All rights reserved.
//

#include <iostream>
using namespace std;

class Polynomial; //전방선언
class Term {
    friend Polynomial; //Polynomial 클래스에서 접근이 가능하다.
private:
    float coef; // 계수
    int exp; // 지수
};

class Polynomial
{
private:
    Term *termArray;
    int capacity; // 배열크기
    int terms; // 0이 아닌 항의 수
public:
    void Print(void);
    void NewTerm(const float theCoeff, const int theExp);
    Polynomial Add(Polynomial b);
    Polynomial Multiply(Polynomial b);
    Polynomial(void); //생성자
};
Polynomial::Polynomial(void)
{
    capacity = 4;
    terms = 0 ;
    termArray = new Term[capacity] ;
}
Polynomial Polynomial::Add(Polynomial b){
    //a(x)(*this의 값)와 b(x)를 더한 결과를 반환한다.
    Polynomial c;
    int aPos = 0, bPos = 0;

    while((aPos < terms) && (bPos < b.terms)){
        if(termArray[aPos].exp == b.termArray[bPos].exp){
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if(t) c.NewTerm(t, termArray[aPos].exp);
            aPos++;
            bPos++;
        } else if (termArray[aPos].exp < b.termArray[bPos].exp){
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        } else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }
    //end of while
    //A(x)의 나머지항들을 추가한다.
    for(; aPos < terms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);

    //B(x)의 나머지항들을 추가한다.
    for(; bPos < b.terms; bPos++)
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

    return c;

} // End of Add
Polynomial Polynomial::Multiply(Polynomial b){
    Polynomial c,temp;
    int aPos = 0, bPos = 0;
    while(bPos < b.terms){
        for(; aPos < terms; aPos++){
            c.NewTerm((termArray[aPos].coef) * (b.termArray[bPos].coef), (termArray[aPos].exp) + (b.termArray[bPos].exp));
        }
        temp = temp.Add(c);
        aPos = 0;
        bPos++;
        if(bPos != b.terms){
            c.capacity = 4;
            c.terms = 0;
        }
    }
    return temp;
}
void Polynomial::Print()
{
    int i ;
    cout << "\n" ;
    if (terms) {
        for (i = 0 ; i < terms-1 ; i++)
            cout << termArray[i].coef << "x^" << termArray[i].exp << " + " ;
        cout << termArray[i].coef << "x^" << termArray[i].exp << "\n" ;
    }
    else
        cout << " No terms " ;
    cout << "\n";

}

// NewTerm함수는 무엇인가?
// 일단 termArray에 차례로 계수와 지수를 입력하고, capacity는 메모리절약을 위해 4로 고정되어있다.
// term이 4가 되면 if문이 실행되면서, capacity의 크기를 두배로 확장하고 그 크기에 맞는 새로운 Term을 생성하고 temp에 복사하고 메모리반환, termarray에 이 값을 넘겨준다.
void Polynomial::NewTerm(const float theCoeff, const int theExp){
    // 새로운 항을 termArray 끝에 첨가한다.
    if(terms == capacity) {
        //termArray의 크기를 두 배로 확장한다.
        capacity *= 2;
        Term *temp = new Term[capacity]; //새로운 배열
        for(int i = 0; i < terms; i++)
        {
            temp[i] = termArray[i];
        }
        delete [] termArray; //그 전 메모리를 반환한다.
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp; // 차례로 terms가 증가한다.


}



// main Function
int main(void) {
    Polynomial A, B, C;
    int i, n, e;
    float c;
    // n : 항의 수 , c : 항의 계수, e : 항의 지수


    cout << "다항식 A의 항의 수 : ";
    cin >> n;
    for(i = 1; i <= n; i++) {
        cout << "다항식 A의 " << i << "번째 항의 계수와 지수: ";
        cin >> c >> e;
        A.NewTerm(c, e);
    }
    A.Print();
    cout << "다항식의 B의 항의 수: ";
    cin >> n;
    for(i = 1; i <= n; i++){
        cout << "다항식 B의" << i << "번째 항의 계수와 지수: ";
        cin >> c >> e;
        B.NewTerm(c, e);
    }
    B.Print();

//    C = A.Add(B);
    C = A.Multiply(B);
    C.Print();

    return 0;
}



