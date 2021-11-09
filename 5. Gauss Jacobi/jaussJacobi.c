#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define EPSILON 0.01

int n;
int flag;

float findSum(int i, float a[][n+1]){
    float sum=0;
    for(int j=0;j<n;j++){
        if(i!=j){
            sum+=fabs(a[i][j]);
        }
    }
    return sum;
}

//checks if Gauss Jacobi Converges or not
bool isMethodApplicable(float a[][n+1]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fabs(a[i][i])>findSum(i,a))
                break;
            else    
                return false;
        } 
    }
    return true;
}

void print(int iteration, float value[n]){
    printf("Iteration %d ", iteration);
    for(int i=0;i<n;i++){
        printf("values[%d] = %f ",i+1,value[i]);
    }
    printf("\n");
}

//Helper function
void findValues(float a[][n+1],int maxIteration, float values_old[n])
{
    int i,j,k,iteration;
    float sum=0;
    float values_new[n];
    for(iteration =1; iteration<=maxIteration; iteration++)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    sum += a[i][j]*values_old[j]; 
                }
            }
            values_new[i]=(a[i][n] - sum)/a[i][i];
        }
        for(k=0;k<n;k++)
        {
            if(fabs(values_old[k]-values_new[k])< EPSILON)
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            print(iteration,values_new);
            return;
        }

        flag = 0;//reseting the flag

        print(iteration,values_new);    //to print intermediate values

        //copy the valuse of unknons toold value array
        for(k=0;k<n;k++)
            values_old[k]=values_new[k];
    }
    print(iteration,values_new);
}


int main(){
    int i,j,maxiterattion;
    printf("\nenter the values of unknowns: ");
    scanf("%d",&n);
    printf("\nEnter no. of iterattion : ");
    scanf("%d",&maxiterattion);

    float a[n][n+1];
    float values[n];
    printf("\nEnter the augmented matrix \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++){
            scanf("%f",&a[i][j]);
        }
    }

    if(!isMethodApplicable(a))
    {
        printf("\nMethod does not converges");
        return 0;
    }
    printf("\nMethod Converges: \n");
    for(i=0;i<n;i++)
        values[i]=0;
    findValues(a,maxiterattion,values);
    return 0;
}