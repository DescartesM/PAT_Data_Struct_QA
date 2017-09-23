#include <iostream>  
#include <vector>  
using namespace std;  
struct TNode{  
    int val;  
    TNode* left;  
    TNode* right;  
    TNode(int x):val(x),left(nullptr),right(nullptr){}  
};  
int height(TNode *&root){  
    if(root==nullptr)  
        return 0;  
    else  
        return max(height(root->left),height(root->right))+1;  //类似求树深度
}  
TNode* singleRotateWithLeft(TNode* &root){//左外侧太深，单旋转  
    TNode* tmp=root->left;  
    root->left=tmp->right;  
    tmp->right=root;  
    return tmp;  
}  
TNode* singleRotateWithRight(TNode* &root){  
    TNode* tmp=root->right;  
    root->right=tmp->left;  
    tmp->left=root;  
    return tmp;  
}  
TNode* doubleRotateWithLeft(TNode* &root){//左内侧太深，双旋转  
    root->left=singleRotateWithRight(root->left);  
    return singleRotateWithLeft(root);  
}  
TNode* doubleRotateWithRight(TNode* &root){  
    root->right=singleRotateWithLeft(root->right);  
    return singleRotateWithRight(root);  
}  
TNode* insert(TNode *root,int x){  
    if(root==nullptr){  
        root=new TNode(x);  
    }else if(x< root->val){  
        root->left=insert(root->left,x);  
        if(height(root->left)-height(root->right)==2){  
            if(x< root->left->val)  
                root=singleRotateWithLeft(root);  
            else  
                root=doubleRotateWithLeft(root);  
        }  
    }else{  
        root->right=insert(root->right,x);  
        if(height(root->right)-height(root->left)==2){  
            if(x> root->right->val)  
                root=singleRotateWithRight(root);  
            else  
                root=doubleRotateWithRight(root);  
        }  
    }  
    return root;  
}  

int main(){  
    int N;  
    cin>>N;  
    int x;  
    TNode *root=nullptr;  
    while(N--){  
        cin>>x;  
        root=insert(root,x);  
    }  
    cout<<root->val<<endl;  
    return 0;  
}  
