#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>
int b[1005];  
int j=0;  
  
int compare(const void * a, const void * b)  
{  
    return *(int *)a - *(int *)b;  
}  
int min(double a, double b)
{
    if(a <b) return a;
    else return b;
}
void BST(int left, int right, int root,int a[])
{
    int flag,h,resume,temp;
    int leftroot, rightroot;
    flag = right - left +1;
    if (!flag)
        return;
    h = log(flag + 1)/log(2);
    resume = min(flag +1 - pow(2,h),pow(2,h-1));
    temp = pow(2,h-1) -1 + resume;

    b[root] = a[temp+left];

    leftroot = root*2 +1;
    rightroot = leftroot +1;

    //recursion 
    BST(left, left+temp-1, leftroot, a);
    BST(left+temp+1, right, rightroot, a);
}
int main(){  
    int N; 
    int i=0;  
    scanf("%d",&N);  
    int a[N];  
    for(i=0;i<N;i++){  
       scanf("%d",&a[i]);  
    }  
    qsort(a,N,sizeof(int),compare);  

    BST(0, N-1,0,a);


    printf("%d",b[0]);  
    for(i=1;i<N;i++){  
        printf(" %d",b[i]);  
    }  
    return 0;
}  
  

   
