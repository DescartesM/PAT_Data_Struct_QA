#include <iostream>
#include <string>
#include <stack>

using namespace std;
//node numbers
#define MAXSIZE 30

int preOrder [MAXSIZE];
int inOrder [MAXSIZE];
int postOrder [MAXSIZE];

void solve(int preL, int inL, int postL, int n)
{
    if (n == 0)
    {
        return;
    }
    if (n == 1)
    {
        postOrder[postL] = preOrder[preL];
        return;
    } 
    int root = preOrder[preL];
    postOrder[postL + n -1] = root;
    int L, R;
    int i;
    for ( i = 0; i < n; ++i)
    {
        if (inOrder[inL + i] == root)
        {
            break;
        }
    }
    L = i; //left node numbers
    R = n- L -1; // right
    //recursed
    solve(preL + 1, inL, postL, L);//for left
    solve(preL + L +1, inL + L + 1,postL + L, R);// for right
}

int main()
{
    //init
    for (int i = 0; i < MAXSIZE; ++i)
    {
        preOrder[i] = 0;
        inOrder[i] = 0;
        postOrder[i] = 0;
    }
    stack<int> inputStack;
    int nodenum;
    cin >> nodenum;
    int data;
    int preIndex = 0, inIndex =0, postIndex = 0;
    string str;

    //input 
    for (int i = 0; i < 2*nodenum; ++i)
    {
        cin >> str;
        if (str == "Push")
        {
            cin >>data;
            preOrder[preIndex++] = data;
            inputStack.push(data);
        }
        else if (str == "Pop")
        {
            inOrder[inIndex++] = inputStack.top();
            inputStack.pop();
        }
    }

    //process
    solve(0, 0, 0, nodenum);

    //output
    for (int i = 0; i < nodenum; ++i)
    {
        if (i == nodenum - 1)
        {
            cout<< postOrder[i] << endl;
        }
        else
        {
            cout<< postOrder[i]<<' ';
        }
    }
}
