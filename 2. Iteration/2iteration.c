#include <stdio.h>
#include <math.h>
#define f(x) cos(x)-3*x+1
#define g(x) (1+cos(x))/3

int main()
{
    int step =1, N;
    float x0,x1,e;
    printf("Enter initial guess : ");
    scanf("%f",&x0);
    printf("Enter tolerance error : ");
    scanf("%f",&e);
    printf("Enter max iteration : ");
    scanf("%d",&N);
    int temp = N;

    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)");

    do{
        x1 = g(x0);
        printf("\n%d\t\t%f\t%f\t%f\t%f",step,x0,f(x0),x1,g(x1));
        step =step +1;
        if(step>N)
        {
            printf("Not COnvergent");
        }
        x0 = x1;
        
    }while((fabs(f(x1)) > e) );
    printf("\nRoots if %f",x1);
    return 0;
}