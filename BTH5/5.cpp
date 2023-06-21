// Tran Ho Khanh Ly 20210561
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if (a % 4 == 0) {
            found = true;
            break;
        }
    }
    if (found) cout << "Yes";
    else cout << "No";
}
// Tran Ho Khanh Ly 20210561