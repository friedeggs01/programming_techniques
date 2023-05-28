// Tran Ho Khanh Ly 20210561
/*
Số nguyên lớn là các số nguyên có giá trị rất lớn 
và không thể biểu diễn bằng các kiểu dữ liệu nguyên 
cơ bản. Để biểu diễn số nguyên lớn, 
ta có thể dùng kiểu struct như sau:

struct bigNum{
     char sign;
     char num[101];
};

Nhiệm vụ các bạn là đa năng hóa các toán 
tử để thực hiện các phép toán số học với 
kiểu dữ liệu số nguyên lớn vừa định nghĩa ở trên.
*/

#include<bits/stdc++.h>
using namespace std;

struct bigNum{
     char sign;
     char num[101];
};

void input(bigNum &num1, bigNum &num2) {
     string tmp;
     cin >> tmp;
     num1.sign = tmp[0];
     int len1 = tmp.length() - 1;
     for (int i=0; i < len1; i++) {
          num1.num[100 - len1 + i + 1] = tmp[i + 1];
     }
     for (int i=0; i < 100-len1+1; i++) {
          num1.num[i] = '0';
     }

     cin >> tmp;
     num2.sign = tmp[0];
     int len2 = tmp.length() - 1;
     for (int i=0; i < len2; i++) {
          num2.num[100 - len2 + i + 1] = tmp[i + 1];
     }
     for (int i=0; i < 100-len2+1; i++) {
          num2.num[i] = '0';
     }
}

void add(char res[], char *num1, char *num2) {
     int c = 0;
     for (int i = 100; i >= 0; i--) {
          int tmp = ((int) num1[i] - 48) + ((int) num2[i] - 48) + c; 
          c = tmp / 10;
          res[i] = tmp % 10 + 48;
     }
}
void sub(char res[], char *num1, char *num2) {
     int c = 0;
     for (int i = 100; i >= 0; i--) {
     int tmp1 = (int) num1[i] - 48;
     int tmp2 = (int) num2[i] - 48;

     if (tmp1 >= tmp2 + c) {
          res[i] = tmp1 - tmp2 - c + 48;
          c = 0;
     } else {
          tmp1 = tmp1 + 10;
          res[i] = tmp1 - tmp2 - c + 48;
          c = 1;
     }
    }

}
void multi(char res[], char *num1, char *num2) {
    for (int i = 0; i < 101; i++) {
        res[i] = '0';
    }

    for (int i = 100; i >= 0; i--) {
        // init 1 array temp
        char tmp[101];

        // add i number 0 to last array
        int k;
        for (k = 0; k < i; k++) {
            tmp[100 - k] = '0';
        }

        int c = 0, sum = 0;
        for(int j = 100; j >= 0; j--){
            sum = ((int) num1[i] - 48) * ((int) num2[j] - 48) + c;
            tmp[k] = (sum % 10) + 48;
            c = sum / 10;
            k--; 
            if (k < 0) break;
        }

        add(res, tmp, res);
    }
}
bool check(char *num1, char *num2) {
     int foo1, foo2;
     for (foo1 = 0; foo1 < 101; foo1++) {
          if (num1[foo1] != '0') break;
     }
     for (foo2 = 0; foo2 < 101; foo2++) {
          if (num2[foo2] != '0') break;
     }
     
     if (foo1 > foo2) return false;
     else if (foo1 < foo2) return true;
     else {
          int foo = foo1;
          while (foo < 101) {
               if (num1[foo] < num2[foo]) return false;
               else if (num1[foo] > num2[foo]) return true;
               else {
                    foo++;
               }
          }
     }
     return true;
}

bigNum operator + (bigNum num1, bigNum num2) {
     bigNum res;

     if (num1.sign == '1' && num2.sign == '1') {
          res.sign = '1';
          add(res.num, num1.num, num2.num);
     } else if (num1.sign == '1' && num2.sign == '0') {
          if (check(num1.num, num2.num)) {
               res.sign = '1';
               sub(res.num, num1.num, num2.num);
          } else {
               res.sign = '0';
               sub(res.num, num2.num, num1.num);
          }
     } else if (num1.sign == '0' && num2.sign == '1') {
          if (check(num1.num, num2.num)) {
               res.sign = '0';
               sub(res.num, num1.num, num2.num);
          } else {
               res.sign = '1';
               sub(res.num, num2.num, num1.num);
          }
     } else {
          res.sign = '0';
          add(res.num, num1.num, num2.num);
     }
     return res;
}

bigNum operator - (bigNum num1, bigNum num2) {
     bigNum res;
     if (num2.sign == '0') {
          num2.sign = '1';
     } else if (num2.sign == '1') {
          num2.sign = '0';
     }
     res = num1 + num2;
     return res;
}
bigNum operator * (bigNum num1, bigNum num2) {
     bigNum res;
     if (num1.sign == '1' && num2.sign == '0') {
          res.sign = '0';
     } else if (num1.sign == '1' && num2.sign == '1') {
          res.sign = '1';
     } else if (num1.sign == '0' && num2.sign == '1') {
          res.sign = '0';
     } else {
          res.sign = '1';
     }
     multi(res.num, num1.num, num2.num);
     return res;
}

void printBigNumber (bigNum number) {
     cout << number.sign;
     int start;
     for (start = 0; start < 101; start++) {
          if (number.num[start] != '0') break;
     }
     for (int i = start; i < 101; i++) {
          cout << number.num[i];
     }
}
int main() {
    bigNum num1, num2;
    input(num1, num2);

    bigNum num3, num4;
    num3.sign = '1', num4.sign = '1';
    for(int i = 0; i < 100; i++){
        num3.num[i] = '0';
        num4.num[i] = '0';
    }
    num3.num[100] = 3 + 48;
    num4.num[100] = 4 + 48;

    bigNum res = num1 * num2 - num3 * num1 + num4 * num2;

    printBigNumber(res); 
}

// Tran Ho Khanh Ly 20210561
