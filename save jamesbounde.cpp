#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef struct Node* Vertex;  
struct Node
{
    int x, y;
    bool visited;
};
vector<Vertex> mystack;
int dis;
int N;
bool flag=false;

double getdistance(Vertex a, Vertex b)
{
    double val;
    val = sqrt(float((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)));  
    return val;
}

void DFS(Vertex point)
{
    point->visited = true;
    if ((50-abs(point->x)) <=dis || (50-abs(point->y)) <=dis)
    {
        cout << "Yes"<<endl;
        exit(0);
    }
    for (int j = 0; j < N; ++j)
    {
        if(!mystack[j]->visited && getdistance(point, mystack[j]) <=dis)
            DFS(mystack[j]);
    }
}

int main()
{

    /////bad choice//////
    Vertex origin = new Node;
    origin->x = 0;
    origin->y = 0;
    origin->visited = false;
    /////////////////
    vector<int> firstjumpchoice;
    cin >> N;
    cin >> dis;
    Vertex* point = new Vertex[N];
    if (dis >= 42.5)
    {
        cout << "Yes"<<endl;
        return 0; 
    }
    for (int i = 0; i < N; ++i)
    {
        int x,y;
        cin >>x>>y;
        point[i] = new Node;
        point[i]->x = x;
        point[i]->y =y;
        point[i]->visited = false;
        // pushback 不能结构体指针。那块内存释放后，指针仍然指向哪里，调用成员导致段错误。
        mystack.push_back(point[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        if(getdistance(origin, mystack[i]) <= 7.5+dis)
            firstjumpchoice.push_back(i);
    }
    if (firstjumpchoice.empty())
    {
        cout << "No" <<endl;
        return 0;
    }
    for (unsigned int i = 0; i < firstjumpchoice.size(); ++i)
        DFS(mystack[firstjumpchoice[i]]);
    cout << "No" <<endl;
    return 0;
}
