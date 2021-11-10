  #include<stdio.h>
  
  float f(float x){
      return (1/(1+x*x));
  }

  int main(){
      int n;
      float a,b,h,sum;
      printf("Enter the vaus of a and b:\n");
      scanf("%f%f",&a,&b);
      printf("Enter the no of interval:");
      scanf("%d",&n);
      h=(b-a)/n;
      sum = f(b)+f(a);
      float i;
      int pos =1;
      for(i=a+h ; i<b;i+=h){
        if(pos%2 == 1)
            sum= sum + 4*f(i);
        else    
            sum = sum + 2*f(i);
        pos++;
      }
      sum = (h*sum)/3;
      printf("\nValue of the integral : %f",sum);
  }