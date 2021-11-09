#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

float defineValue(float x)
{
    return x*x*x - 2*x- 5;
}

float findx(float x1, float x2)
{
    return (x1*defineValue(x2) - x2*defineValue(x1))/(defineValue(x2)-defineValue(x1));
}

int main()
{
    int i=1,maxIteration;
    float x1,x2,x3,x;
    printf("\nenter maximum no. of iteration ");
    scanf("%d",&maxIteration);
    do{
        printf("\nEnter initial value of x1 and x2 : ");
        scanf("%f%f",&x1,&x2);
        if( (defineValue(x1)*defineValue(x2) ) > 0)
        {
            printf("\nRoot is invalid");
            continue;
        }
        else{
            printf("\nRoot lies betwwen %f and %f\n",x1,x2);
            break;
        }
    }while(1);

    x=findx(x1,x2);
    do{
        if(defineValue(x)*defineValue(x1)   <   0)
            x2 = x;
        else    
            x1 = x;
        printf("'\nIteration = %d\troots = %f",i,x);
        x3=findx(x1,x2);
        if(fabs(x3-x)<EPSILON)
        {
            //print root
            printf("\nRoot = %f\tTotal Iteration = %d",x,i);
            return 0;
        }
        x = x3;
        i++;
    }while(i<=maxIteration);
    printf("\nRoot = %d\ttTotal Iteration = %d",x,i);

}