#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(){
    int n=100000;  // 0.1 Million
    int prime;
    int NumPrimes =0;      // it will tell total numbers of prime value

    double StartTime, EndTime, ExecTime;

    StartTime = omp_get_wtime();
#pragma omp  parallel 
{
 int Thradid= omp_get_thread_num();

    #pragma omp for schedule(dynamic, 100) // Dynamic scheduling with chunk size 50
    for (int i=2;i<=n;i++) 
    {
        prime=0;                // it will reset prime 
        for(int a=2; a<i; a++){
            if(i%a ==0){
            // #pragma omp atomic  
                prime=1;            // it may Race Codition 
                break;
            }
        }
        if (prime==0) {
       //
       // printf("%d is Prime\n",i);
            #pragma omp atomic
            NumPrimes ++;                // this is Race statement
        } 
    }
}
EndTime = omp_get_wtime();

ExecTime = EndTime - StartTime;
printf("The Total prime values are %d \n",NumPrimes);
printf("The Exection Time is %f \n ", ExecTime);
    return 0;
}