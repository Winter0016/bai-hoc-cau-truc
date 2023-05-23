#include <iostream>
using namespace std;
struct node
{
    int key;
    int info;
    node*next;
    node*left;
    node*right;
};

void insertnode(node*&root,int x)
{
    if(root==NULL){
        root=new node();
        root->key=x;
        root->left=root->right=NULL;
    }
    else if(x<root->key)
        insertnode(root->left,x);
    else if(x>root->key)
        insertnode(root->right,x);
}
node*createnode(int x)
{
    node*p=new node;
    p->info=x;
    p->next=NULL;
    return p;
}
void input(node*&head,node*&tail,int x)
{
    node*p=createnode(x);
    if(head==NULL)
        head=tail=p;
    else{
        tail->next=p;
        tail=p;
    }
}
void findsmallest(node*head,node*tail,int &smallest)
{
    node*p1=head;
    node*p3=p1;
    while(p3!=NULL)
    {
        if(p3->info>1)
            smallest=p3->info;
        p3=p3->next;
    }
    node*p2=p1->next;
    while(p2!=NULL){
        if(p2->info<smallest&&p2->info>1)
            smallest=p2->info;
        p2=p2->next;
    }
}
void LNR(node* root,int &y,int smallest) {
    if (root != NULL) {
        LNR(root->left,y,smallest);
        if(root->key==2||root->key==3){
            y=y-1;
        }
        else if(y!=0&&root->key>=smallest&&root->key%2!=0&&root->key%3!=0){
            cout<<"";
            y=y-1;
        }

        else{
            cout<<root->key<<" ";
        }
        LNR(root->right,y,smallest);
    }
}
int main()
{
    node*root=NULL;
    int x;
    node*head=NULL;
    node*tail=NULL;
    while(1)
    {
        cin >>x;
        if(x==0)
            break;
        input(head,tail,x);
        insertnode(root,x);
    }
    if(root==NULL)
        cout<<"Not found tree!";
    else{
        int y;
        cin>>y;
        int smallest;
        findsmallest(head,tail,smallest);
        LNR(root,y,smallest);
    }
}
