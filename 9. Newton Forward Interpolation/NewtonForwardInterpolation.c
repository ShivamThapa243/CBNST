#include<stdio.h>
#include<math.h>

int main(){
    int i,j,n,fact;
    float a[100][100], x, u1, u, y;
    printf("Enter no. of terms : \n");
    scanf("%d",&n);
    printf("Enter the value of X:\n");
    for(i = 0; i < n; i++){
        scanf("%f",&a[i][0]);
    }
    printf("\nEnter the value of y :\n");
    for(i = 0 ; i < n ; i++)
        scanf("%f",&a[i][1]);
    printf("Enetr the value of X for which you want y:\n");
    scanf("%f",&x);

    //find the difference table

    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++)
        {
            a[i][j] = a[i+1][j-1] - a[i][j-1]; 
        }
    }

    //print different table
    printf("The difference table is as follow :\n");
    
    for(i =0 ;i<n;i++){
        for(j=0;j<=n-i;j++)
            printf("%f ", a[i][j]);
        printf("\n");
    }

    //find u
    u=(x - a[0][0])/(a[1][0]-a[0][0]);

    //initial value y,u1,fact

    y = a[0][1];
    u1 = u;
    fact =1;
    for(i=2;i<=n; i++){
        y = y + (u1*a[0][i])/fact;
        
        fact = fact *i;
        u1 = u1*(u-(i+1));
    }
    printf("\n\nValue of x = %f is %f",x,y);
}