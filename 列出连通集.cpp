/*for vc6.0 version 
so silly......
basic DFS & BFS in gragh
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10

int graph[MAX][MAX] = {0};
bool visited[MAX] = {false};
vector<int> res;
int N,E;

void DFS(int x)
{
    visited[x] =true;
    res.push_back(x);
    for (int i = 0; i < N; ++i)
    {
        if(graph[x][i] != 0 && visited[i] == false)
            DFS(i);
    }
}

void BFS(int x)
{
    queue<int> myque;
    myque.push(x);
    visited[x] =true;
    res.push_back(x);
    while(! myque.empty())
    {
        int temp = myque.front();
        myque.pop();
        for (int i = 0; i < N; ++i)
        {
            if(graph[temp][i] != 0 && visited[i] == false)
            {
                visited[i] =true;
                res.push_back(i);
                myque.push(i);
            }
        }
    }
}

int main()
{
    cin >>N >>E;
    for (int i = 0; i < E; ++i)
    {
        int x1, x2;
        cin>>x1 >> x2;
        graph[x1][x2] = 1;
        graph[x2][x1] = 1;
    }
    for (int j = 0; j < N; ++j)
    {
        res.clear();
        vector <int>().swap(res);
        if (!visited[j])
        {
            DFS(j);
            cout << "{ ";
            for (unsigned int k = 0; k < res.size(); ++k)
                cout << res[k]<<' ';
            cout <<"}"<<endl;
        }        
    }
    //reinit visited
    for (int yjn =0;yjn<MAX;++yjn)
        visited[yjn] = false;
    for (int jj = 0; jj < N; ++jj)
    {
        res.clear();//clear elements
        vector <int>().swap(res);//free memory
        if (!visited[jj])
        {
            BFS(jj);
            //format of output
            cout << "{ ";
            for (unsigned int kk = 0; kk < res.size(); ++kk)
                cout << res[kk]<<' ';
            cout <<"}"<<endl;
        }
    }
    return 0;
}
