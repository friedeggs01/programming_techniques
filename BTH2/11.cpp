// Tran Ho Khanh Ly 20210561
/*
Tính tích hai đa thức
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m + 1];
    for (int i = 0; i <= m; i++) {
        cin >> b[i];
    }

    int c[n + m + 1];
    for (int i = 0; i <= n+m; i++) {
        c[i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    int res = c[0];
    for (int i = 1; i <= n+m; i++) {
        res = res ^ c[i];
    }
    cout << res;

}

// Tran Ho Khanh Ly 20210561

