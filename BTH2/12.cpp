// Tran Ho Khanh Ly 20210561
/*
Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. 
Cô cho một danh sách với mỗi phần tử có dạng <key, value> 
và yêu cầu An sắp xếp danh sách đó giảm dần 
theo giá trị value. Nếu 2 phần tử có value giống nhau 
thì sắp xếp giảm dần theo key.

Hãy viết một chương trình sử dụng hàm 
nặc danh để giúp An làm bài tập.
*/

#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long int, long int> a, pair<long int, long int> b) {
    if (a.second > b.second) return true;
    if (a.second == b.second)
        if (a.first >= b.first) return true;
        return false;
}

int main() {
    vector<pair<long int, long int>> a;
    int key, value;
    while (cin >> key && cin >> value) {
        a.push_back({key, value});
    }

    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < a.size(); i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
}
// Tran Ho Khanh Ly 20210561