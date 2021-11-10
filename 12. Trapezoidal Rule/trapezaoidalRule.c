#include <stdio.h>

float f(float x)
{
    return x*x*x ;
}

int main(){
    int n;
    float a,b,h,sum=0;
    printf("Enter the value of a and b\n");
    scanf("%f%f",&a,&b);
    printf("Enter the interval\n");
    scanf("%d",&n);
    
    //step size
    h=(b-a)/n;

    sum = f(a)  +f(b);
    for(float i=a+h;i<b;i=i+h){
        sum = sum + 2*f(i);
    }
    sum=(h*sum)/2;
    printf("\nValue of integral = %f",sum);
}