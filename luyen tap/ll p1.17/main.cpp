#include <iostream>
using namespace std;

struct node
{
    int info;
    node*next;
};
struct List
{
    node*head;
    node*tail;
};
node*createnode(int x)
{
    node*p=new node;
    p->info=x;
    p->next=NULL;
    return p;
}
void input(List &l,int x)
{
    node*p=createnode(x);
    if(l.head==NULL)
        l.head=l.tail=p;
    else{
        p->next=l.head;
        l.head=p;
    }
}
void output(List l,int x)
{
    node*p=l.head;
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}
void checkrepeat(List l,int &Max)
{
    node*p1=l.head;
    Max=1;
    while(p1!=NULL){
        int sum=1;
        node*p2=p1->next;
        while(p2!=NULL){
            if(p2->info==p1->info){
                sum++;
            }
            p2=p2->next;
        }
        if(sum>Max)
            Max=sum;
        p1=p1->next;
    }
}
void Print(List l,int Max)
{
    node*p1=l.head;
    while(p1!=NULL){
        int sum=1;
        node*p2=p1->next;
        while(p2!=NULL){
            if(p2->info==p1->info){
                sum++;
            }
            p2=p2->next;
        }
        if(sum>=Max)
            cout<<p1->info<<": "<<Max<<endl;
        p1=p1->next;
    }
}
int main()
{
    List l;
    l.head=NULL;
    l.tail=NULL;
    int x;
    while(1){
        cin>>x;
        if(x==0)
            break;
        input(l,x);
    }
    if(l.head==NULL)
        cout<<"Danh sach rong.";
    else{
        output(l,x);
        int Max;
        checkrepeat(l,Max);
        Print(l,Max);
    }
}
