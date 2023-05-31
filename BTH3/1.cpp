// Tran Ho Khanh Ly 20210561
/*
Dãy Lucas được định nghĩa bởi Ln=Ln−1+Ln−2
và bắt đầu bởi L0=2, L1=1. Viết hàm tính số Lucas thứ n
*/
#include<bits/stdc++.h>
using namespace std;
int lucas(int n) {
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (n == 0) return 2;
    if (n == 1) return 1;
    return lucas(n-1) + lucas(n-2);
}

int main() {
    cout << lucas(2);
    return 0;
}
// Tran Ho Khanh Ly 20210561