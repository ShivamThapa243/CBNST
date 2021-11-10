#include<stdio.h>
#include<math.h>
int main(){
    int i,j,fact,n;
    float x,y,u,u1,a[100][100];
    printf("enter the no. of terms \n");
    scanf("%d",&n);
    printf("enter the values of x\n");
    for(i=0;i<n;i++)
    scanf("%f",&a[i][0]);
    printf("enter the values of y\n");
    for(i=0;i<n;i++)
    scanf("%f",&a[i][1]);
    printf("enter the value of x for which you want y:\n");
    scanf("%f",&x);

    //difference table

    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++){
            a[i][j] = a[i+1][j-1] - a[i][j-1];
        }
    }
    printf("The difference table\n");
    for(i=0;i<n;i++){
        for(j=0;j<=n-i;j++)
            printf("%f\t",a[i][j]);
        printf("\n");
    }

    //value of u
    u = (x - a[n-1][0])/(a[1][0]-a[0][0]);
    y = a[n-1][1];

    //initial k,u1,j
    
    u1= u;
    fact =1;
    j=2;
    for(i = n-2; i>=0; i--){
        y = y + (u1 * a[i][j])/fact;
        //update k,u1,j
        fact=fact*j;
        u1 = u1*( u + (j-1));
        j++;
    }
    printf("\n\nVale at x = %g is : %f",x,y);
}