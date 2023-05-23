#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
};
void insert(Node*& root, int z)
{
    if (root == NULL)
    {
        root = new Node();
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
void LNR(Node* root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}
void LRN(Node*root){
    if(root!=NULL){
        LRN(root->left);
        LRN(root->right);
        cout<<root->key<<" ";
    }
}
void RNL(Node*root){
    if(root!=NULL){
        RNL(root->right);
        cout<<root->key<<" ";
        RNL(root->left);
    }
}
void RLN(Node*root){
    if(root!=NULL){
        RLN(root->right);
        RLN(root->left);
        cout<<root->key<<" ";
    }
}
void NLR(Node*root){
    if(root!=NULL){
        cout<<root->key<<" ";
        NLR(root->left);
        NLR(root->right);
    }
}
void NRL(Node*root){
    if(root!=NULL){
        cout<<root->key<<" ";
        NRL(root->right);
        NRL(root->left);
    }
}
int main() {
    Node* root = NULL;
    int key;
    while (true) {
        cin >> key;
        if (key == 0) {
            break;
        }
        insert(root, key);
    }
    cout<<"LNR: ";
    LNR(root);
    cout<<endl;
    cout<<"LRN: ";
    LRN(root);
    cout<<endl;
    cout<<"RNL: ";
    RNL(root);
    cout<<endl;
    cout<<"RLN: ";
    RLN(root);
    cout<<endl;
    cout<<"NLR: ";
    NLR(root);
    cout<<endl;
    cout<<"NRL: ";
    NRL(root);
    return 0;
}
