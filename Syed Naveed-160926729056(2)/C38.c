#include <stdio.h>
int main()
{
    int a,n,Result;
     printf("Enter a Number:");
     scanf("%d",&a);

     printf("Enter Shift Number:");
     scanf("%d",&n);

     Result=a>>n;

     printf("Result=%d",Result);

     return 0;
}
