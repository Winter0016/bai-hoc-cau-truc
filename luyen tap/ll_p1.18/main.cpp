#include <iostream>
using namespace std;
struct node
{
    int info;
    int capnhat;
    node*next;
};
struct List
{
    node*head;
    node*tail;
};
node*createnode(int x,int hehe)
{
    node*p=new node;
    p->info=x;
    p->next=NULL;
    p->capnhat=hehe;
    return p;
}
void input(List &l,int x,int hehe)
{
    node*p=createnode(x,hehe);
    if(l.head==NULL)
        l.head=l.tail=p;
    else{
        l.tail->next=p;
        l.tail=p;
    }
}
void output(List l)
{
    node*p=l.head;
    while(p!=NULL)
    {
        if(p->capnhat%2==0)
            cout<<p->info<<" ";
        p=p->next;
    }
}
int main()
{
    List l;
    l.head=NULL;
    l.tail=NULL;
    int x;
    int hehe=1;
    while(1)
    {
        cin>>x;
        if(x==0)
            break;
        input(l,x,hehe);
        hehe++;
    }
    if(l.head==NULL)
        cout<<"Danh sach rong.";
    else{
        output(l);
    }
}
