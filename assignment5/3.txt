#include <iostream>
using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
};

void insert(node*& root, int z)
{
    if (root == NULL)
    {
        root = new node();
        root->key = z;
        root->left = root->right = NULL;
    }
    else if (z < root->key)
    {
        insert(root->left, z);
    }
    else if (z > root->key)
    {
        insert(root->right, z);
    }
}
void countleafnode(node*root,int &Count)
{
    if (root != NULL)
    {
        countleafnode(root->left,Count);
        if(root->left==NULL&&root->right==NULL)
            Count++;
        countleafnode(root->right,Count);
    }
}
void leafnode(node* root)
{
    if (root != NULL)
    {
        leafnode(root->left);
        if(root->left==NULL&&root->right==NULL)
            cout<<root->key<<" ";
        leafnode(root->right);
    }
}

int main()
{
    node* root = NULL;
    int z, y;
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        cin >> z;
        insert(root, z);
    }
    int Count=0;
    countleafnode(root,Count);
    cout<<Count<<endl;
    leafnode(root);
}
