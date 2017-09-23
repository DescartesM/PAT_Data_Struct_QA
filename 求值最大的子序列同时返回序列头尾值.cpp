#include <iostream>  
#define maxsize 100000+100  
using namespace std;   
int res[3];
int MaxSubseqSum(int A[], int N)
{
    int ThisSum, MaxSum, Start, End;
    int flag,temp;
    flag = temp = 0;
    MaxSum = -1;
    ThisSum = Start = End = 0;
    for (int i = 0; i < N; ++i)
    {
        /* code */
        ThisSum += A[i];
        if (ThisSum > MaxSum)
        {
            /* code */
            MaxSum = ThisSum;
            if (flag == 0)
            {
                Start = temp;
                flag = 1;
            }
            End = i;
        }
        else if (ThisSum < 0)   //algorthm core, analyze everytime, if it is negtive ,drop it
        {
            ThisSum = 0;
            temp = i + 1;
            flag = 0;
        }    
    }
    if (MaxSum <0)
    {
        res[0] = 0;
        res[1] = A[0];
        res[2] = A[N-1];
    }
    else
    {
        res[0] = MaxSum;
        res[1] = A[Start];
        res[2] = A[End];
    }

    return 0;
}

int main(){  
    int num, max;
    int A[maxsize];  
    cin>>num;  
    for(int i = 0;i < num; i++)
    {  
        cin>>A[i];  
    }  
    MaxSubseqSum(A,num);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;  
    return 0;  
}  

