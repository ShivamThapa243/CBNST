#include<stdio.h>

void convertUpperTriangular(float a[3][4], int n) //n is number of columns
{
    float ratio;
    for(int i=0;i<n;i++){
         for(int j=0;j<n;j++)
          {
             if(j>i){
                  ratio = a[j][i]/a[i][i];
                  for(int k=0;k<n+1;k++) {
                     a[j][k] = a[j][k] -(ratio*a[i][k]);
                  }
               }    
        }
    }
    printf("\nUpper triangular matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }
}

//perform back substitution
void backSubstitution(float a[3][4], float val[3], int n)
{
    float sum;
    val[n-1] = a[n-1][n]/a[2][2];

    for(int i=n-2;i>=0;i--){
        sum =0;
        for(int j=i+1;j<3;j++)
        {
            sum = sum + a[i][j]*val[j];
        }
        val[i]=(a[i][n] - sum)/a[i][i];
    }
    
}

int main(){
    int n;
    printf("Enter the no. of obseravtion \n");
    scanf("%d",&n);

    float x[n],y[n], sumx=0, sumy=0,sumxy=0,sumx2=0,sumx2y=0,sumx3=0,sumx4=0;
    printf("\nEnter the values ox x:\n");
    for(int i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("\nEnter the values ox y:\n");
    for(int i=0;i<n;i++)
        scanf("%f",&y[i]);
    for(int i=0;i<n;i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2 += x[i]*x[i];
        sumx2y += x[i]*x[i]*y[i];
        sumx3 += x[i]*x[i]*x[i];
        sumx4 += x[i]*x[i]*x[i]*x[i];
    }
    float a[3][4];
    a[0][0] = sumx2;
    a[0][1] = sumx;
    a[0][2] = n;
    a[0][3] = sumy;
    a[1][0] = sumx3;
    a[1][1] = sumx2;
    a[1][2] = sumx;
    a[1][3] = sumxy;
    a[2][0] = sumx4;
    a[2][1] = sumx3;
    a[2][2] = sumx2;
    a[2][3] = sumx2y;
    
    //upper Triangle
    convertUpperTriangular(a,3);

    //Backsubstitution
    float val[3];
    backSubstitution(a,val,3);

    printf("\nParabolic Equuation\n");
    printf("y : %.2fx^2 + %.2fx + %.2f",val[0],val[1],val[2]);
    
}