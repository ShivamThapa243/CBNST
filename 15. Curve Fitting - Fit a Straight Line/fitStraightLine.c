#include<stdio.h>
int main(){
    int n;
    printf("Enter the no. of terms\n");
    scanf("%d",&n);
    float sumx=0,sumy=0,sumxy=0,sumx2=0,x[n],y[n];
    float mat[2][3], a,b;
    printf("Enter the valus of x\n");
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
    }
    printf("Enter the valus of y\n");
    for(int i=0;i<n;i++){
        scanf("%f",&y[i]);
    }
    for(int i=0;i<n;i++){
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2 += x[i]*x[i]; 
    }
    //solving the equation a and b
    //solving using gauss elimination method
    
    mat[0][0] = n;
    mat[0][1] = sumx;
    mat[0][2] = sumy;
    mat[1][0] = sumx;
    mat[1][1] = sumx2;
    mat[1][2] = sumxy;

    float ratio = mat[1][0]/mat[0][0];
    for(int i=0; i<3 ; i++){
        mat[1][i]=(mat[1][i]-ratio*mat[0][i]);
    }

    printf("\nMatrix after applying gauss elimination\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<=2;j++){
            printf("%.2f\t",mat[i][j]);
        }
        printf(("\n"));

    }
    b = mat[1][2]/mat[1][1];
    a = (mat[0][2]-mat[0][1]*b)/mat[0][0];

    printf("\n\nEquation : y = %.2f + %.2fx ",a,b);
}