//  https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void inOrder(TreeNode* r, vector<int>& vec)
        {
        if(!r) return;
        inOrder(r->left, vec);
        vec.push_back(r->val);
        inOrder(r->right, vec);  
        }

    int kthSmallest(TreeNode* root, int k) {
        // vector<int> v;
        // inOrder(root, v);
        // return v[k-1];
        int rank = 0;
        return kthHelper(root, k, rank);

    }

    int kthHelper(TreeNode* root, int k, int& rank)
    {
        if (!root) return -1;
 
        int left = kthHelper(root->left, k, rank);
        rank++;

        if(k < rank) return left;
        if(k == rank) return root->val;
        return kthHelper(root->right, k, rank);
    } 

};