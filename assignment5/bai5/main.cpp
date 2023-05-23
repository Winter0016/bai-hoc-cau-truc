#include <iostream>
using namespace std;

struct TNode {
    int key;
    TNode* pLeft;
    TNode* pRight;
};

typedef TNode* Tree;

void Initialize(Tree& T) {
    T = NULL;
}

void InsertNode(Tree& T, int x) {
    if (T != NULL) {
        if (T->key == x) {
            return;
        }
        else if (T->key > x) {
            InsertNode(T->pLeft, x);
        }
        else { // T->key < x
            InsertNode(T->pRight, x);
        }
    }
    if (T == NULL) {
        T = new TNode;
        T->key = x;
        T->pLeft = T->pRight = NULL;
    }
}

void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->pLeft);
        cout << T->key << " ";
        LNR(T->pRight);
    }
}

void Input(Tree& T) {
    int x;
    while (1) {
        cin >> x;
        if (x <= 0) {
            break;
        }
        InsertNode(T, x);
    }
}

void Search(Tree T, int x, int &count) {
    if (T != NULL) {
        count++;
        if (T->key == x) {
            return;
        }
        else if (x > T->key) {
            return Search(T->pRight, x, count);
        }
        else {
            return Search(T->pLeft, x, count);
        }
    }
    count = -1;
    return;
}

void Output(Tree T) {
    int x;
    while (cin >> x && x > 0) {
        int count = -1;
        Search(T, x, count);
        cout << count << endl;
    }
}

int main() {
    Tree T;
    Initialize(T);
    Input(T);
    Output(T);
    return 0;
}
