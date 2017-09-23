#include <iostream>

using namespace std;  

#define MAX 10001
// represent a set, value means its father

int Find(int S[], int x)
{
    if (S[x] < 0)
        return x;
    else
        // recureived to cut down the path
        return S[x] = Find(S, S[x]);
}

void Union(int S[], int root1, int root2)
{
    // union the different set to one
    // gui bing algorithm add little to the big make the broader not deeper
    if (S[root2] < S[root1])
    {
        S[root2] += S[root1];
        S[root1] = root2;
    }
    else
    {
        S[root1] += S[root2];
        S[root2] = root1; 
    }
}

void input(int S[])
{
    int num1,num2;
    int root1, root2;
    cin >> num1;
    cin >> num2;
    // -1 cause a map 0~N-1 to 1~N
    root1 = Find(S, num1 -1);
    root2 = Find(S, num2 -1);
    if (root1 != root2)
    {
        Union(S, root1, root2);
    }
}

void check(int S[])
{
    int num1, num2;
    int root1, root2;
    cin >> num1;
    cin >>num2;
    root1 = Find(S, num1 -1);
    root2 = Find(S, num2 -1);
    if (root1 == root2)
        cout <<"yes"<<endl;
    else
        cout << "no"<<endl;
}
void stop(int S[], int N)
{
    int temp = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i]<0)
            temp++;
    }
    if(temp == 1)
        cout << "The network is connected."<<endl;
    else
        printf("There are %d components.\n", temp);
}

int main()
{
    int N, S[MAX];
    char flag;
    cin >> N;
    //init the set S
    for (int i = 0; i < N; ++i)
        S[i] = -1;
    cin >> flag;
    //main judge
    while(flag != 'S')
    {
        switch (flag)
        {
        case 'I': input(S);
            break;
        case 'C': check(S);
            break;
        }   
        cin >> flag;     
    }
    stop(S, N);

    return 0;
}
