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
    void QuickSort(int * a, int left, const int right) {
        // 중추키(pivot)는 a[left]로 선정한다.
        // a[left] <= a[rigth + 1]라고 가정한다.
        if(left < right) {
            int i = left;
            int j = right + 1;
            int pivot = a[left];
            do {
                do { i++;} while (a[i] < pivot);
                do { j--;} while (a[j] > pivot);
                if(i < j) swap(a[i], a[j]);
            } while(i < j);
            swap(a[left], a[j]);

            QuickSort(a, left, j - 1);
            QuickSort(a, j + 1, right);
        }
    }
    void Merge(int *a,int *sorted, int m, int middle, int n) {
        int i = m;
        int j = middle + 1;
        int k = m;

        while(i <= middle && j <=n) {
            if(a[i] <= a[j]) {
                sorted[k] = a[i];
                i++;
            } else {
                sorted[k] = a[j];
                j++;
            }
            k++;
        }
        if(i > middle) { // i가 전부 담긴경우 j삽입.
            for(int t = j; t <= n; t++) {
                sorted[k] = a[t];
                k++;
            }
        } else { // 그 반대.
            for(int t = i; t <= middle; t++) {
                sorted[k] = a[t];
                k++;
            }
        }
        for(int t = m; t <= n; t++) {
            a[t] = sorted[t];
        }
    }
    void MergeSort(int *a, int m, int n) {
        int tempList[10] = {};
        if(m < n) {
            int middle = (m + n) / 2;
            MergeSort(a, m, middle);
            MergeSort(a, middle + 1, n);
            Merge(a, tempList, m, middle, n);
        }
    }


};

int main() {
    int arr[10] = {0,5,1,2,3,6,13,23,4,2}; //a[0]는 사용하지 않았다.
    Sort sort;
//    sort.InsertionSort(arr, 9);
//    sort.QuickSort(arr, 1, 10);
    sort.MergeSort(arr, 1, 9);
    for(int i = 1; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}