// Tran Ho Khanh Ly 20210561
/*
Bài 12: Lược đồ
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> graph;
vector<vector<int>> neighbor;
vector<int> value;
void input(){
    cin >> n;
    graph.push_back(-1);//dat linh canh
    for(int i = 0 ;i<n;i++){
        int tmp;
        cin >> tmp;
        graph.push_back(tmp);
    }
    graph.push_back(-1);//linh canh
}

int main(){
    input();
    for(int i = 1;i<=n;i++){
        int part = graph.at(i);
        vector<int> a;
        a.push_back(part);
        
        int now = i;
        while(true){
            if(graph.at(now - 1) < part){
                break;
            } else {
                a.push_back(graph.at(now - 1));
                now -= 1;
            }
        }
        now = i;
        while(true){
            if(graph.at(now + 1) < part){
                break;
            } else {
                a.push_back(graph.at(now + 1));
                now += 1;
            }
        }
        value.push_back(part*a.size());
    }
    sort(value.rbegin(),value.rend());
    cout << value.at(0);
}
// Tran Ho Khanh Ly 20210561