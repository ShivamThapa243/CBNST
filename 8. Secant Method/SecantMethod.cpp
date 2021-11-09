// Cprogram to imlement secant method

#include<stdio.h>
#include<math.h>
#define EPSILON 0.001

float f(float x){
    return x*x*x - 5*x +1;
}

float findX(float x1, float x2){
    return ( x1*f(x2) - x2*f(x1) ) / ( f(x2) - f(x1) );
}

int main(){
    int maxIteration, i=1;
    float x1,x2,x;
    printf("\nEnter max no. of iteration: ");
    scanf("%d",&maxIteration);
    printf("Enter the value of x1 and x2 (Boundaries) : \n");
    scanf("%f%f",&x2,&x2);
    x = findX(x1,x2); 
    do{
        x1 = x2;
        x2 = x;
        printf("Iteration = %d\tRoot = %f\n",i,x);
        x = findX(x1,x2);
        if(fabs(x-x2) < EPSILON)
        {
            printf("Root = %f\tTotal Iteration = %d\n",x,i+1);
            return 0;
        }
        i++;
    }while(i<=maxIteration);
    printf("Final Root = %f",x);
    return 0;
}