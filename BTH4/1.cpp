// Tran Ho Khanh Ly 20210561
/*
Đảo ngược một danh sách liên kết đơn
Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết:
Thêm một phần tử vào đầu danh sách liên kết
In danh sách
Đảo ngược danh sách liên kết (yêu cầu độ phức tạp thời gian O(N)
và chi phí bộ nhớ dùng thêm O(1))
*/
#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node* p = new Node(data);
    p->next = head;
    return p;
}

// print the list content on a line
void print(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *cur = head, *pre = NULL, *nex = NULL;
    while (cur != NULL) {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }

    return pre;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
// Tran Ho Khanh Ly 20210561
