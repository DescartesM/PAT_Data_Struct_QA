#include <iostream>
#include <vector>
using namespace std;

#define INF 101
int graph[101][101];

void floyd(int N)
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int k = 1; k <= N; ++k)
            {
                if (graph[j][i] + graph[i][k] < graph[j][k])
                    graph[j][k] = graph[j][i] + graph[i][k];
            }
}

int main()
{
    int N, M;
    cin >> N >> M;
    //init graph
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                graph[i][j] =0;
            else
                graph[i][j] = INF;
        }
    }
    for (int i = 1; i <= M; ++i)
    {
        int from, to, val;
        cin >>from >>to >>val;
        graph[from][to] = graph[to][from] = val;
    }
    //process
    floyd(N);
    vector<int> maxdis;
    // find the max distance for each point
    for (int i = 1; i <= N; ++i)
    {
        int temp = 0;
        for (int j = 1; j <= N; ++j)
            if (graph[i][j] > temp)
                temp = graph[i][j];
        maxdis.push_back(temp);
    }
    //find the min of maxdistance and markdown the index
    int minmaxdis = 10001;
    int mintag = -1;
    for (int i = 0; i < N; ++i)
    {
        if (minmaxdis > maxdis[i])
        {
            mintag = i +1;
            minmaxdis = maxdis[i];
        }
    }
    //output
    if (minmaxdis == INF)   // in case of no solve way
        cout <<'0'<<endl;
    else
        cout <<mintag<<' '<<minmaxdis<<endl;
    return 0;
}
