#include<stdio.h>
#include<omp.h>
#include<time.h>

int main(){
    // Finding Prime Number by Sequential
int n=50;  //  0.1 M
int NumPrimes=0;

clock_t start =clock();

for(int i=2; i<=n; i++)
{    // As we know that every integer divided by itself
    int prime=1;

    for(int j=2; j<i; j++)
    {
        if (i%j==0)
        {
            prime=0;
            break;
        }
    }
    if (prime==1)
    {
       printf("The %d is prime\n",i);
        NumPrimes ++;
    }

    //else if( prime==0) printf("There is No prime Number");  
}
clock_t end =clock();

double time_taken = (double)(end - start)/CLOCKS_PER_SEC;

//printf("The exec_time is %f \n",time_taken);
//printf("The Total Prime values are %d \n",NumPrimes);
    return 0;

}