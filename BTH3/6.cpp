// Tran Ho Khanh Ly 20210561
/*
Tìm ước chung lớn nhất của hai số cho trước
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b) {
    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    int temp;
    while (a%b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd(a, b);
    return 0;
}
// Tran Ho Khanh Ly 20210561