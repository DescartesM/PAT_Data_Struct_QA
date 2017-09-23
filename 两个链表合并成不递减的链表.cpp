#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print( List L ); /* empty node will return NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* your code */
List Merge(List L1, List L2)
{
    List p, q, temp;
    PtrToNode L = (PtrToNode)malloc(sizeof(struct Node));
    L ->Next = NULL;
    temp = L;
    p = L1 ->Next;
    q = L2 ->Next;

    while(q && p)
    {
        if (p->Data < q->Data)
        {
            temp ->Next = p;
            p = p ->Next;
            temp = temp ->Next; 
        }
        else
        {
            temp ->Next = q;
            q = q ->Next;
            temp = temp ->Next;            
        }
    }
    temp ->Next = NULL;
    if (p)
        temp ->Next = p;
    if (q)
        temp ->Next = q;
    //output format need
    L1 ->Next = NULL;
    L2 ->Next = NULL;
    return L;
}
List Read()
{
    PtrToNode Begin,Last;
    int num,val;
    // inpit nums
    scanf("%d",&num);
    if (num == 0)
    {
        return NULL;
    }
    // convinent
    Begin = (PtrToNode)malloc(sizeof(struct Node));
    Begin -> Next = NULL;

    Last = Begin;
    while(num --)
    {
        scanf("%d", &val);
        PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
        temp ->Next = NULL;
        temp ->Data = val;
        Last ->Next = temp;
        Last = temp;
    }

    return Begin;
}

void Print( List L)
{
    if (L->Next == NULL)
    {
        printf("NULL\n");
        return;
    }

    while(L = L->Next)
    {
        printf("%d", L->Data);
    }
    putchar('\n');
}

