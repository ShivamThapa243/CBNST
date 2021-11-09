#include<stdio.h>
#include <math.h>
int main(){
    int i,j,k,n;
    float a[10][11],x[10],s,t;
    printf("\nenter the number of unknowns:");
    scanf("%d",&n);
    printf("\nenter the values\n");
    for(i =0 ; i < n; i++)
    {
        for(j=0; j<=n;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    //upper triangular matrix
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++){
            t=a[j][i]/a[i][i];
            for(k=0;k<=n;k++)
                a[j][k] = a[j][k] - a[i][k]*t;
        }
    }
    printf("\nThe upper triangular matrix\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<=n;j++){
            printf("%.4f\t",a[i][j]);
        }
    }

    //backward substitution

    for(i=n-1;i>=0;i--){
        s =0 ;
        for(j=i+1;j<n;j++){
            s=s+a[i][j]*x[j];
        }
        x[i]=(a[i][n]-s)/a[i][i];
    }

    printf("\nvalues of unknowns : ");
    for(i=0; i<n; i++)
    {
        printf("\n x%d = %f",i+1,x[i]);
    }
}