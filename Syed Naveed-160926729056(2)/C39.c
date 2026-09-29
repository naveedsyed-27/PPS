#include <stdio.h>
int main ()
{
    int choice;
    int a=10,b=5;
    int Sum=a+b;
    int Difference=a-b;
    int product=a*b;
    int Division=a/b;
    printf("1.Sum\n");
    printf("2.Differnce\n");
    printf("3.Product\n");
    printf("4.Division\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case1:
            printf("Sum=%d",Sum);
            break;

        case2:
            printf("Difference=%d",Difference);
            break;

        case3:
            printf("Product=%d",product);
            break;

        case4:
            printf("Division=%d",Division);
            break;

        default:
            printf("Invalid Choice");

}
    return 0;
}
