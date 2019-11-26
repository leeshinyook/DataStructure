#include <iostream>
using namespace std;

class Sort
{
public:
    Sort(){};
    int SeqSearch(int *a, const int n, const int &k);    // 순차탐색
    int BinarySearch(int *a, const int &k, const int n); // 이진탐색
    char compare(int num1, int num2);

private:
};

int Sort::SeqSearch(int *a, const int n, const int &k)
{
    // 요구사항
    // a[0:n-1]을 왼쪽에서 오른쪽으로 탐색한다.
    // a[i]의 키 값이 k와 같은 가장 작은 i를 반환한다.
    // 위와같은 i가 없을경우 -1을 반환한다.
    int i;
    for (i = 0; i < n && a[i] != k; i++)
    {
        if (i >= n)
            return -1;
    }
    return i;
}
int Sort::BinarySearch(int *a, const int &k, const int n)
{
    // 정렬된 배열 a[0],..., a[n - 1]에서 x를 탐색한다.
    for (int left = 0, right = n - 1; left <= right;)
    {
        int middle = (left + right) / 2;
        switch (compare(k, a[middle]))
        {
        case '>':
            left = middle + 1;
            break;
        case '<':
            right = middle - 1;
            break;
        case '=':
            return middle;
        }
    }
    return -1; // not Found
}
char Sort::compare(int num1, int num2)
{
    if (num1 == num2)
    {
        return '=';
    }
    else if (num1 > num2)
    {
        return '>';
    }
    else
    {
        return '<';
    }
}

int main()
{
    Sort array;
    int unsorted_array[10] = {2, 3, 1, 5, 7, 9, 4, 6, 10};
    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << array.SeqSearch(unsorted_array, 10, 4) << endl;
    cout << array.BinarySearch(sorted_array, 6, 10) << endl;
}
