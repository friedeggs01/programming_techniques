// Tran Ho Khanh Ly 20210561
/*
Viết chương trình in ra tất cả
các dãy con của một dãy cho trước.
*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n]; 
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i; k <= j; k++){
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
}
// Tran Ho Khanh Ly 20210561