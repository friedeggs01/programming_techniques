// Tran Ho Khanh Ly 20210561
/*
Thao tác với vector
Cho hai vector, hãy xóa hết các phần tử chẵn, 
sắp xếp giảm dần các số trong cả 2 vector và trộn lại 
thành một vector cũng được sắp xếp giảm dần.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 == 0) {
            a.erase(a.begin() + i);
            i--;
        }
    }
}

void sort_decrease(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(), a.end(), greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> c;
    for (int v : a) {
        c.push_back(v);
    }
    for (int v : b) {
        c.push_back(v);
    }
    sort_decrease(c);
    return c;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}

// Tran Ho Khanh Ly 20210561