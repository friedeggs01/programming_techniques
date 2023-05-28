#include <stdio.h>
int main()
{
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    /*****************
    # YOUR CODE HERE #
    *****************/
    // Gan dia chi cua x cho ptr
    ptr = &x;
    // Cong gia tri cua x them 100
    *ptr += 100;
    // Gan dia chi cua y cho ptr
    ptr = &y;
    // Cong gia tri cua y them 100
    *ptr += 100;
    // Gan dia chi cua z cho ptr
    ptr = &z;
    // Cong gia tri cua z them 100
    *ptr += 100;
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
} 