TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root)
        return new TreeNode(val);
    if(val < root->val)
        root->left = insertIntoBST(root->left, val);
    else if(val > root->val)
        root->right = insertIntoBST(root->right, val);
    return root;
}

void mergeInorder(TreeNode* root1, TreeNode* root2) {
    if (!root2) return;
    mergeInorder(root1, root2->left);
    root1 = insertIntoBST(root1, root2->val);
    mergeInorder(root1, root2->right);
}

TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    mergeInorder(root1, root2);
    return root1;
}
