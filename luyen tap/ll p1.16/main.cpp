#include <iostream>
using namespace std;
struct node
{
    int info;
    int check;
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
    p->check=NULL;
    p->next=NULL;
    return p;
}
void input(List &l,int x)
{
    node*p=createnode(x);
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
    cout<<"Danh sach vua nhap la: ";
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}
void checkrepeat(List l)
{
    cout<<"So lan xuat hien cua tung phan tu trong danh sach la:"<<endl;
    node*p1=l.head;
    while(p1!=NULL){
        node*p2=p1->next;
        int Count=1;
        while(p2!=NULL){
            if(p2->info==p1->info&&p1->check==NULL){
                Count++;
                p2->check=1;
            }
            p2=p2->next;
        }
        if(p1->check==NULL){
            cout<<p1->info<<": "<<Count<<endl;
        }
        p1=p1->next;
    }
}
int main()
{
    List l;
    l.head=l.tail=NULL;
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
        output(l);
        checkrepeat(l);
    }
}
