 #include <stdio.h>
 #include <math.h>

 float fun(float x)
 {
     return x*x*x - x -1;
 }

 float bisect(float *x, float a, float b, int *itr)
 {
     *x= (a+b)/2;
     ++(*itr);
     printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
 }

 int main(){
     int itr = 0, maxmitr;
     float x, a, b , x1, allerr;
     do{
         printf("\nEnter the value of a and b : ");
         scanf("%f %f",&a,&b);
     }
     while((fun(a)*fun(b))>0);
     printf("\nEnter the value of allowed error and maximum itr : ");
         scanf("%f %d",&allerr,&maxmitr);
    
    bisect(&x,a,b,&itr);

    do{
        if( ( fun(a) * fun(x) ) < 0)
        {
            b= x;
        }
        else
            a= x;
        bisect(&x1,a,b,&itr); 
        if(fabs(x1-x)<allerr)
        {
            printf("after %d iteration, root = %6.4f\n", itr, x1);
            return 0;
        }       
        x=x1;
    }
    while(itr < maxmitr);
    printf("The solutioon does not coonverge or iteration are not sufficient");
    return 0;

 }