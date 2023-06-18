// Tran Ho Khanh Ly 20210561
/*
Bài 11: Bảo vệ lâu đài
*/
#include<bits/stdc++.h>
using namespace std;
struct wall{
    int ai;
    int ki;

    wall(int ai,int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

struct compare{
    bool operator() (wall a, wall b){
        int ra, rb;

        if(a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if(b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

int n,s;
priority_queue<wall,vector<wall>,compare> now;
int tong_dich=0,dich_da_giet=0;
void input(){
    cin >> n >> s;
    int i = 0;
    while(i<n){
        int ai,ki;
        cin >> ai >> ki;
        now.push(wall(ai,ki));
        tong_dich += ai;
        i++;
    }
}
void algo(){
    while(!now.empty() && s > 0){
        wall a = now.top();now.pop();
        if(a.ai <= a.ki){
            dich_da_giet += a.ai;
        } else {
            int now_enemy = a.ai - a.ki;
            now.push(wall(now_enemy,a.ki));
            dich_da_giet += a.ki;
        }

        s -= 1;
    }
}

int main(){
    input();
    algo();
    cout << tong_dich - dich_da_giet;
}
// Tran Ho Khanh Ly 20210561