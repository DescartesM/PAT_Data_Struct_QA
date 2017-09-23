#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

#define MAX 10001
vector<int>  v[MAX];

int BFS(int x)
{
    int count = 1;// include itself
    bool visited[MAX] = {false};
    visited[x] = true;
    int deadline= 6, last = x, tail;
    int temp;
    queue<int>myque;
    myque.push(x);

    while(!myque.empty())
    {
        temp = myque.front();
        myque.pop();
        for (unsigned int i = 0; i < v[temp].size(); ++i)
        {
            if(!visited[v[temp][i]])
            {
                visited[v[temp][i]] =true;
                myque.push(v[temp][i]);
                count++;
                tail = v[temp][i];
            }      
        }
        if(temp == last)
        {
            deadline--;
            last = tail;
        }
        if (deadline == 0)
            break;
    }
    return count;
}

int main()
{
    int N, M;// nums of points and edgess
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int x1, x2;
        cin >>x1 >>x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }
    for (int i = 1; i <= N; ++i)
    {
        int temp;
        double res;
        temp = BFS(i);
        res = temp*1.0 / N*100.0;
        printf("%d: %.2f%%\n",i,res);
    }
    return 0;
}
