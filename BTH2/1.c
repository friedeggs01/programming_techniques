//Tran Ho Khanh Ly 20210561
/*
Viết hàm tính độ dài cạnh huyền 
của tam giác theo độ hai cạnh góc vuông.
*/
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   return sqrt(x*x + y*y);
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}
// Tran Ho Khanh Ly 20210561