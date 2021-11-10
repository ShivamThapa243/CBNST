#include<stdio.h>
float f(float x)
{
    return 1/(1+x*x);
}
int main(){
    int n;
    float a,b,h,sum=0;
    printf("Entre the value of a and b:\n");
    scanf("%f%f",&a,&b);
    printf("Enter the interval size : \n");
    scanf("%d",&n);
    h=(b-a)/n;

    //position
    int pos =1;
    sum = f(a) + f(b);
    for(float i = a+h; i<b; i+=h)
    {   
        if(pos%3 == 0)
            sum = sum + 2*f(i);
        else
            sum = sum + 3*f(i);
        pos++;
    }
    sum = (sum*h)*3/8;
    printf("\n\nValue of intergral = %f",sum); 
}
