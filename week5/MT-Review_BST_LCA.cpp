#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->val > n1 && root->val > n2) return findLCA(root->left, n1, n2);
    if (root->val < n1 && root->val < n2) return findLCA(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int n1 = 5, n2 = 15;
    Node* lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->val << endl;
    } else {
        cout << "LCA does not exist" << endl;
    }

    // Free allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
