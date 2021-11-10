#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of terms : \n");
    scanf("%d",&n);
    float X[n],Y[n],x,term,sum=0;
    printf("Enter the values of x : \n");
    for(int i=0;i<n;i++)
    scanf("%f",&X[i]);
    printf("Enter the values of y : \n");
    for(int i=0;i<n;i++)
    scanf("%f",&Y[i]);
    printf("Enter the values of x for wich you want y : \n");
    scanf("%f",&x);

    //formula
    for(int i=0;i<n; i++){
        term =1;
        for(int j=0;j<n;j++){
            if(i!=j){
                term=term*((x - X[j])/(X[i] - X[j]));
            }
        }
        sum = sum+ term*Y[i];
    }
    printf("\n\nValue of x = %g at y = %f",x,sum);
}