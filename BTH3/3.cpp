// Tran Ho Khanh Ly 20210561
/*
Một người xuất phát tại thành phố 1, muốn đi thăm tất cả các thành phố khác, 
mỗi thành phố đúng 1 lần và quay về 1. Chi phí để đi từ thành phố i
sang thành phố  j là  ci,j. Hãy tìm tổng chi phí nhỏ nhất có thể
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}
bool check(int k, int i) {
    if(mark[i] == 1) return false;
    return true;
}
void solution() {
    best = min(best, curr);
}
//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        /*****************
        # YOUR CODE HERE #
        *****************/
        if(check(k, i)) {
            mark[i] = 1;
            x[k] = i;
            curr += c[x[k-1]][i];

            if (k == n) {
                curr += c[x[n]][1];
                solution();
                curr -= c[x[n]][1];
            }
            else TRY(k+1);

            mark[i] = 0;
            curr -= c[x[k-1]][i];
        }
    }
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
// Tran Ho Khanh Ly 20210561