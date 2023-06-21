// Tran Ho Khanh Ly
/*
Bài 13: Đếm xâu con
*/
#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int resolution;
map<int, int> dif;

void input(){
    cin >> str;
    n = str.length();
    resolution = 0;
}

int calc(int b){
    int tmp = 0;
    for(int i=1; i<b; i++)
        tmp += i;
    return tmp;
}

void solve(){
    int slogan0 = 0, slogan1 = 0;
    map<int, int>::iterator it;
    int i = 0;
    while(i<n){
        if(str[i] == '0') slogan0++;
        else slogan1++;

        int tmp = slogan1 - slogan0; 
        it = dif.find(tmp);
        if(it != dif.end()){ 
            it->second += 1;
        } 
	else {
            dif.insert({tmp, 1});
        }
	i++;
    }

    it = dif.begin();
    while(it != dif.end()){
        resolution += calc(it->second);
        if(it->first == 0) 
		resolution += it->second;
        it++;
    }
}

int main(){
    input();
    solve();

    cout << resolution;
    return 0;
}
// Tran Ho Khanh Ly