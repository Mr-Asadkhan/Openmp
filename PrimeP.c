#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(){
    int n=100000;      // 0.1 Million  By_default Scope in parallel region is Shared
    int NumPrimes =0;      // it will tell total numbers of prime value
    int prime;
    double startT,endT,ExecT;
    startT=omp_get_wtime();
#pragma omp  parallel 
{
    int Thradid= omp_get_thread_num();    // In side Parallel region Declared Vvariable Scope is Private
    
    //int NumPrimes =0;      // it will tell total numbers of prime value
    #pragma omp for schedule(static, 25000)
    for (int i=2;i<=n;i++) 
    {
        prime=0;                // it will reset prime 
        for(int a=2; a<i; a++){
            if(i%a ==0){
                prime=1;            
                break;
            }
        }
        if (prime==0) {
        printf("%d is Prime\n",i);
           #pragma omp atomic
            NumPrimes ++;               // its Race Codition 
        }  
        if (i==n) printf("The Total prime values are %d \n",NumPrimes);
    }   
}
 endT= omp_get_wtime();
 ExecT= endT-startT;
 //printf("The Exection time is %f \n", ExecT);
return 0;
}