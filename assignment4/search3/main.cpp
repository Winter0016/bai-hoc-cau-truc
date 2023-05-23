#include <iostream>

using namespace std;

struct node {
    double floatValue;
    string stringValue;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

node* Create_Node(double x, string s) {
    node* p1 = new node;
    p1->floatValue = x;
    p1->stringValue = s;
    p1->pNext = NULL;
    return p1;
}

void AddTail(List& l, node* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void input(List& l){
    int a, b;
    while (1) {
        cin >> a >> b;
        if (b == 0)
            break;
        double a1 = a;
        double floatValue = a1/b;
        string stringValue = to_string(a)+"/"+ to_string(b);
        node* p = Create_Node(floatValue, stringValue);
        AddTail(l, p);
    }
}

void output(List l){
    node *p = l.pHead;
    while(p != NULL){
        cout << p->stringValue << " ";
        p = p->pNext;
    }
}

void outputEqualFloat(List l, double value, string holder){
    node *p = l.pHead;
    bool check;
    cout << endl;
    while(p != NULL){
        if(p->floatValue == value){
            check = true;
        }
        if(p == l.pTail && p->floatValue != value){
            check = false;
        }
        if(check == true){
            cout << "Cac phan so bang " << holder << " co trong danh sach la: ";
            while(p != NULL){
                if(p->floatValue == value)
                    cout << p->stringValue << " ";
                p = p->pNext;
            }
            return;
        }
        else if(check == false){
            cout << "Khong co phan so nao bang " << holder << " trong danh sach.";
            return;
        }
        p = p->pNext;
    }
}

int main(){
    List l;
    CreateList(l);
    input(l);
    if(l.pHead == NULL)
        cout << "Danh sach rong.";
    else{
        int c, d;
        cin >> c >> d;
        cout << "Danh sach vua nhap la: ";
        output(l);
        string holder = to_string(c) + "/" + to_string(d);
        double c1 = c;
        outputEqualFloat(l, c1/d, holder);
    }
    return 0;
}
