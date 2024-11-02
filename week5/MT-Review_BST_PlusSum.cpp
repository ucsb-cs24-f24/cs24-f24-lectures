#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void AddHelper(TreeNode* node, int& total) {
    if (!node) return;

    // Traverse the right subtree first
    if (node->right) {
        AddHelper(node->right, total);
    }

    // Update the current node's value
    total += node->val;
    node->val = total;

    // Traverse the left subtree
    if (node->left) {
        AddHelper(node->left, total);
    }
}

TreeNode* convertBST(TreeNode* root) {
    if (!root) return nullptr;

    int total = 0;
    AddHelper(root, total);

    return root;
}


void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    cout << "Original BST in-order: ";
    printInOrder(root);
    cout << endl;

    convertBST(root);

    cout << "Greater Tree in-order: ";
    printInOrder(root);
    cout << endl;

    // Free allocated memory (simple cleanup, not complete)
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
