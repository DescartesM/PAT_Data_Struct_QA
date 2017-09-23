#include <iostream>
using namespace std;  
#define MAX 1001
#define MIN -10001

int H[MAX], size;

void create()
{
    size = 0;
    H[0] = MIN;
}

void insert(int X)
{
    int i;
    for (i = ++size; H[i/2] > X; i/=2)
    {
        H[i] = H[i/2];
    }
    H[i] = X;
}
int main()
{
    int N, M, x,j;
    cin >> N;
    cin >> M;
    create();
    for (int i = 0; i < N; ++i)
    {
        cin >> x;
        insert(x);
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> j;
        cout << H[j];
        while(j > 1)
        {
            j /= 2;
            cout <<' '<< H[j];
        }
        cout << '\n';
    }
    return 0;
}
