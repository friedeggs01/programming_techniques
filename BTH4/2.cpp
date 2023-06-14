// Tran Ho Khanh Ly 20210561
/*
Tính diện tích tam giác
Một điểm trong không gian 2 chiều được biểu diễn bằng pair. 
Hãy viết hàm double area(Point a, Point b, Point c) tính diện tích 
tam giác theo tọa độ 3 đỉnh. Trong đó, Point là kiểu được định nghĩa 
sẵn trong trình chấm như sau: using Point = pair<double, double>;
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   double area;
   area = fabs((a.first * b.second) + (b.first * c.second) + (c.first * a.second) - (b.first * a.second) - (c.first * b.second) - (a.first * c.second));
   return area;
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
// Tran Ho Khanh Ly 20210561