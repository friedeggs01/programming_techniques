// Tran Ho Khanh Ly
/*
Viết chương trình nhập vào 2 ma trận vuông 
cùng kích thước n*n, trong đó n nhập từ bàn phím.
Sau đó tính tổng và tích của hai ma trận đó và 
đưa kết quả ra màn hình. 
Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ 
cho các ma trận.
*/
#include<bits/stdc++.h>
using namespace std;

void allocate_mem(int ***mt, int n){
   *mt = new int*[n];
   for (int i = 0; i < n; i++) {
    (*mt)[i] = new int[n];
   }
}

void input(int **mt, int n){
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(*(mt + i) + j);
    }
        }
}

void output(int **mt, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << *(*(mt + i) + j) << " ";
        }
        cout << "\n";
    }
}

int sum(int **tong, int **mt1, int **mt2, int n){
    // Calculate the sum of two matrices
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
                *(*(tong + i) + j) = *(*(mt1 + i) + j) + *(*(mt2 + i) + j);
        }
    }
}
int multiply(int **tich, int **mt1, int **mt2, int n){
    // Calculate the multiphy of two matrices
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
                *(*(tich + i) + j) = *(*(mt1 + i) + j) * *(*(mt2 + i) + j);
        }
    }
}

void free_mem(int **mt, int n){
    // Free memory
   for(int i = 0; i < n; i++){
    delete[]mt[i];
   }
   delete[]mt;
}

int main() {
    int n, **mt1, **mt2, **tong, **tich;
    printf("Enter n = ");
    cin >> n;
    allocate_mem(&mt1, n);
    allocate_mem(&mt2, n);
    allocate_mem(&tong, n);
    allocate_mem(&tich, n);
    input(mt1, n);
    input(mt2, n);
    sum(tong, mt1, mt2, n);
    multiply(tich, mt1, mt2, n);
    output(tong, n);
    output(tich, n);
    free_mem(mt1, n);
    free_mem(mt2, n);
    return 0;
}
// Tran Ho Khanh Ly