#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

float f(float x){
    return x*x*x - 3*x - 5;
}

float g(float x){
    return 3*x*x - 3;
}

int main()
{
    int maxIteration, i;
    float x1, x2, x, x0;
    printf("Enter maximum no. of iteration\n");
    scanf("%d",&maxIteration);
    do{
        printf("Enter the value of x1 and x2 : \n");
        scanf("%f%f",&x1,&x2);
    
        if(f(x1)*f(x2) > 0)
        {
            printf("Boundary values are invalid ");
            continue;
        }
        else{
            printf("Roots lies between %f and %f \n",x1,x2);
            break;
        }
    }while(1);
    
    //find x0
    if(fabs(f(x1))<fabs(f(x2)))
        x0 = x1;
    else    x0=x2;

    //apply succesive approximate to find the roots between x1 and x2
    for(int i =1;i<=maxIteration;i++){
       
        x=x0-(f(x0)/g(x0));
        
        if(fabs(x-x0)<EPSILON)
        {
            printf("Iteration = %d\tFinal Root = %f\n",i,x);
            return 0;
        }
        printf("Iteration = %d\tRoots=%f\n",i,x);
        x0=x;
    }
    printf("Root = %f\tTotal Iteration = %d",x,--i);
}