#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
struct Node
{
    int address;
    int data;
    int next;
};

int main()
{
    int N,K; // total N, reversed K
    vector<Node> v(100000);
    vector<Node> v_new;
    vector<Node> result;
    Node temp;
    Node root;
    int tmp_add;
    //INPUT
    // add data next    first add num_total num_reversed
    scanf("%d", &root.address);
    if (root.address == -1)
    {
        printf("-1\n");  
        return 0;
    }
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &temp.address,&temp.data,&temp.next);
        v[temp.address] =temp;
    }

    // build new vector ,shun xu cun shu
    tmp_add = root.address;
    while(tmp_add != -1)
    {
        v_new.push_back(v[tmp_add]);
        tmp_add = v[tmp_add].next;  // update
    }

    //reverse
    int t =0;
    N = v_new.size();
    //reversed part
    while(N>= (K+t))
    {
        for (int i = (K + t)-1 ; i >= t; i--)
        {
            result.push_back(v_new[i]);
        }
        t += K;
    }
    //remain part
    for (int i = t; i < N; ++i)
    {
        result.push_back(v_new[i]);
    }

    //output
    for (int i = 0; i < N-1; ++i)
    {
        result[i].next = result[i+1].address;
        printf("%05d %d %05d\n", result[i].address, result[i].data, result[i].next);
    }
    printf("%05d %d %d\n",result[N-1].address,result[N-1].data,-1);  
    return 0;

}
