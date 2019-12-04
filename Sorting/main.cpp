#include <iostream>
using namespace std;

class Sort {
public:
    Sort(){};
    void InsertionSort(int *a, const int n) { // a[1:n]을 오름차순으로
        for(int j = 2; j <= n; j++) {
            int temp = a[j];
            Insert(temp, a, j - 1); // a[j]가 삽입 원소이다.
        }
    }
    void Insert(const int &e, int *a, int i) {
        // e를 정렬된 리스트 a[1: i]에 삽입하여 결과
        // 리스트 a[1: i+1]도 정렬되게 한다.
        // 배열 a는 적어도 i+2 원소를 포함할 공간을 가지고 있어야한다.
        // a[0]에는 -infi가 저장되어있다.
        while(e < a[i]) {
            a[i + 1] = a[i]; // i한칸씩 밀어준다.
            i--;
        }
        a[i + 1] = e;
    }
};

int main() {
    int arr[10] = {0,5,1,2,3,6,13,23,4,2}; //a[0]는 사용하지 않았다.
    Sort sort;
    sort.InsertionSort(arr, 9);
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}