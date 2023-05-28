// Tran Ho Khanh Ly 20210561
/*
Viết hàm tính tổng các phần tử trong hai mảng.
Yêu cầu sử dụng function template 
để cho phép hàm làm việc với các 
mảng số nguyên lẫn số thực.
*/

#include <iostream>
using namespace std;

//# viết hàm arr_sum
/*****************
# YOUR CODE HERE #
*****************/
template <typename T>
T arr_sum(T a[], int n, T b[], int m) {
    T sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    for(int i = 0; i < m; i++){
        sum += b[i];
    }
    
    return sum;
}
int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
// Tran Ho Khanh Ly 20210561