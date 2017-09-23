#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define INF 0x6FFFFFFF  
struct Node
{
    int dis;
    int cost;
};
Node city[500][500];
bool visited[500] ={false};
int dist[500]; // use namespace "distance" may crack with standard libarary function ?
int price[500];
int N, M;
vector<int> path;
void dijkstra(int start, int destination)
{
    
    //think in set
    for (int i = 0; i < N; ++i)
    {
        price[i] = city[start][i].cost;
        dist[i] = city[start][i].dis;
        path.push_back(-1);
    }
    //add start point to my set
    visited[start] = true;
    dist[start] = 0;
    for (int i = 0; i < N; ++i)
    {   
        int min = INF;
        //find the current min dist city for my set
        for (int j = 0; j < N; ++j)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j]; 
                start = j;
            }
        }
        //add new min dis point to my set
        visited[start] = true;
        //update the dis and cost for new set
        for (int k = 0; k < N; ++k)
        {
            if (!visited[k] && city[start][k].dis + min < dist[k]) // if through new point can get shorter dist
            {
                dist[k] = city[start][k].dis + min;
                price[k] = city[start][k].cost + price[start];
                path[k]=start;
            }
            else if (!visited[k] && city[start][k].dis + min == dist[k])    // if same dist choice the less price
                if (price[k] > city[start][k].cost + price[start])
                {
                    price[k] = city[start][k].cost + price[start];  
                    path[k] = start;
                }
        }
    }
    path.push_back(destination);
}
int main()
{
    //init
    int  start, destination;
    cin >>N >>M >>start >>destination;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            city[i][j].dis = INF;
            city[i][j].cost = INF;
        }
    }
    for (int i = 0; i < M; ++i)
    {
        int from, to, dis, cost;
        cin >>from >>to >>dis >>cost;
        city[from][to].dis = city[to][from].dis = dis;
        city[from][to].cost = city[to][from].cost = cost;
    }
    //process
    dijkstra(start, destination);
    int temp = destination;
    stack<int> ans;
    ans.push(temp);
    while(path[temp] != -1)
    {
        ans.push(path[temp]);
        temp = path[temp];
    }
    ans.push(start);
    while(!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
    cout<< dist[destination]<<' '<<price[destination]<<endl;
    return 0;
}
