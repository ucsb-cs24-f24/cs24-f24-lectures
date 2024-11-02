#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL;

    // Swap the left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void printTree(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    invertTree(root);

    cout << "Inverted tree: ";
    printTree(root);
    cout << endl;

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