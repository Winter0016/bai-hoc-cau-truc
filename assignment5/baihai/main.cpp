#include <iostream>
using namespace std;
struct Node {
    int key;
    int info;
    Node*next;
    Node* left;
    Node* right;
};
void insert(Node*& root, int key) {
    if (root == NULL) {
        root = new Node();
        root->key = key;
        root->left = root->right = NULL;
    } else if (key < root->key) {
        insert(root->left, key);
    } else if (key > root->key) {
        insert(root->right, key);
    }
}
Node *createnode(int key)
{
    Node*p=new Node;
    p->info=key;
    p->next=NULL;
    return p;
}
void input(Node*&head,Node*&tail,int key)
{
    Node *p=new Node;
    p=createnode(key);
    if(head==NULL)
        head=tail=p;
    else{
        tail->next=p;
        tail=p;
    }
}
void check(Node* head,Node* tail,float y)
{
    Node *p=head;
    float sum=0;
    while(p!=NULL){
        sum=sum+p->info;
        p=p->next;
    }
    float average=sum/y;
    Node*p1=head;
    int hehe=0;
    while(p1!=NULL){
        if(p1->info==average){
            hehe=1;
            break;
        }
        p1=p1->next;
    }
    if(hehe==0){
        cout<<"0"<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
}
void LNR(Node* root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}
void CountTotal(Node*root,int &a)
{
    if(root!=NULL){
        CountTotal(root->left,a);
        a=a+root->key;
        CountTotal(root->right,a);
    }
}
int main() {
    Node* root = NULL;
    int z;
    int x=1;
    int y;
    cin>>y;
    Node *head=NULL;
    Node *tail=NULL;
    while (x<=y) {
        cin >> z;
        input(head,tail,z);
        insert(root, z);
        x++;
    }
    int a=0;
    CountTotal(root,a);
    cout<<"TOTAL: "<<a<<endl;
    check(head,tail,y);
    LNR(root);
    return 0;
}
