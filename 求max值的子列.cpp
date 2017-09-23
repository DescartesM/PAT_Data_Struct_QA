#include <iostream>  
#define maxsize 100000+100  
using namespace std;  
  
int A[maxsize];  
int S[maxsize];  

int MaxSubseqSum(int A[], int N)
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for (int i = 0; i < N; ++i)
    {
        /* code */
        ThisSum += A[i]
        if (ThisSum > MaxSum)
        {
            /* code */
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0)   //algorthm core, analyze everytime, if it is negtive ,drop it
            ThisSum = 0;
    }
    return MaxSum;
}

int main(){  
    int num, max;
    cin>>num;  
    for(i = 0;i < num; i++)
    {  
        cin>>A[i];  
    }  
    max = MaxSubseqSum(A,num);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    cout<<max<<endl;  
    return 0;  
}  

