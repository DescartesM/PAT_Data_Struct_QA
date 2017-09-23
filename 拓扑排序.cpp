#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct AdjNode
{
    int adjv;
    int weight;
    AdjNode* next;
};
struct VNode
{
    AdjNode* firstedge;
    int indegree;
    int earliest;
};

int main()
{
    int N, M;
    cin >>N >>M;
    vector<VNode> graph(N);
    int comtime;
    vector<int> end;
    queue<int> myque;
    for (int i = 0; i < N; ++i)
    {
        graph[i].firstedge = NULL;
        graph[i].earliest = -1;
        graph[i].indegree = 0;
    }
    while(M --)
    {
        int from, to, val;
        cin >>from >>to >> val;
        AdjNode* newnode = new AdjNode; 
        newnode ->adjv = to;
        newnode ->weight = val;
        newnode ->next = graph[from].firstedge;
        graph[from].firstedge = newnode;
        graph[to].indegree++;
    }
    int count=0;
    for (int i = 0; i < N; ++i)
    {
        if (!graph[i].indegree)
        {
            myque.push(i);
            graph[i].earliest = 0;
        }
    }
    while(!myque.empty())
    {
        int temp;
        temp = myque.front();
        myque.pop();
        count++;
        if (!graph[temp].firstedge)
            end.push_back(temp);
        while(graph[temp].firstedge)
        {
            int w;
            w = graph[temp].firstedge ->adjv;
            if (graph[temp].earliest + graph[temp].firstedge->weight > graph[w].earliest)
                graph[w].earliest = graph[temp].earliest + graph[temp].firstedge->weight;  
            if (!(--graph[w].indegree))  
                myque.push(w);  
            graph[temp].firstedge = graph[temp].firstedge->next;  
        }     
    }  
    if (count != N) printf("Impossible");  
    else 
    {  
        comtime = -1;  
        for (unsigned int i = 0;i < end.size();i++) 
        {  
            if (graph[end[i]].earliest>comtime)  
                comtime = graph[end[i]].earliest;  
        }  
        printf("%d", comtime);  
    }  
    return 0;  


}



