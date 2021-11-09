#include<stdio.h>
#include<math.h>
int n;

void convertToDiagonal(float a[][n+1], int n){
    int i,j,k,x,y;
    float ratio;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                ratio = a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                    a[j][k] = a[j][k] -(ratio*a[i][k]);

                //print the matrix after changed rrow (Intermediate forms)

                /*printf("Intermediate forms:\n");
                for(x=0;x<n;x++)
                {
                    for(y=0;y<n+1;y++)
                        printf("%f ",a[x][y]);
                    printf("\n");
                }
                printf("\n");*/
            }
        }
    }
    printf("\nDiiagonal Matrix \n");
    for(i =0; i<n; i++){
        for(j=0;j<n+1;j++){
            printf("%.4f  ",a[i][j]);
        }
        printf("\n");
    }
}

void printUnknowns(float a[][n+1], int n)
{
    int i;
    printf("Values of unkonowns are:\n");
    for(i=0;i<n;i++){
        printf("Value of variable %d = %f\n", i, a[i][n]/a[i][i]);
    }
}

int main(){
    int i, j, k, x, y;
    float ratio;
    printf("Enter no. of unknowns: ");
    scanf("%d",&n);
    float a[n][n+1];
    printf("\nEnter the Augmented matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            scanf("%f",&a[i][j]);
        }
    }
    convertToDiagonal(a,n);
    printUnknowns(a,n);
}