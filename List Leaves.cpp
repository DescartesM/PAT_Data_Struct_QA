#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define MAX 10
#define NULL -1

typedef struct TreeNode
{
    int left;
    int right;
}Tree;
Tree T[MAX];

void LevelOrderTraversal(Tree T[],int root)
{
    queue<int> queue;
    queue.push(root);
    int flag = 1;
    while(!queue.empty())
    {
        int temp = queue.front();
        queue.pop();
        if(T[temp].left == NULL && T[temp].right == NULL)
        {
            cout << temp ;
            if (!queue.empty())
                cout<< ' ';
        }
        else
        {
            if (T[temp].left != NULL)
                queue.push(T[temp].left);
            if (T[temp].right != NULL)
                queue.push(T[temp].right);
        }

    }
    return;
}

int main()
{
    int N;
    char left, right;
    int root;
    int flag[MAX] = {0};
    cin >> N;
    //build tree and find root;
    if(N != 0)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> left;
            cin >> right;
            if (left != '-')
            {
                T[i].left = left -'0';
                flag[T[i].left] = 1;
            }
            else
                T[i].left = NULL;
            if (right != '-')
            {
                T[i].right = right -'0';
                flag[T[i].right] = 1;
            }
            else
                T[i].right = NULL;
        }
        for (int i = 0; i < N; ++i)
        {
            if(flag[i] == 0)
            {
                root = i;
                break;  // because N < MAX
            }
        }    
        // ceng bian li using queue
        LevelOrderTraversal(T, root);
    }
    return 0;
}
