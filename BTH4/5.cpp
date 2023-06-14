// Tran Ho Khanh Ly 20210561
/*
Viết hàm thực hiện thuật toán DFS không sử dụng đệ quy
trên đồ thị biểu diễn bằng danh sách kề vector< list<int> > .
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát 
từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải 
trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những 
đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (!S.empty()) {
        int x = S.top();
        S.pop();
        if (!visited[x]) {
            visited[x] = true;
            cout << x << endl;
        }
        for (int y : adj[x]) {
            if (!visited[y]) {
                S.push(y);
            }
        }
    }
}
int main()
{
    int n = 7;
    vector<list<int>> adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}
// Tran Ho Khanh Ly 20210561