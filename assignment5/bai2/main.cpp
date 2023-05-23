#include <iostream>
using namespace std;

struct Node {
    int key;
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

void printInorder(Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int key;
    while (cin >> key && key != 0) {
        insert(root, key);
    }
    printInorder(root);
    return 0;
}
