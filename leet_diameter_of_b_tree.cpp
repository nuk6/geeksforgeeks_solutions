// P : https://leetcode.com/problems/diameter-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ht(TreeNode* r) {
        if(!r) return 0;
        int hL = (r->left) ? ht(r->left) : 0;
        int hR = (r->right) ? ht(r->right) : 0;
        return 1 + max(hL,hR);
    }
    int d(TreeNode* root) {
        if(!root) return 0;
        int hL = (root->left) ? ht(root->left) : 0;
        int hR = (root->right)? ht(root->right) : 0;
        //cout << "Height = " << ht(root);
        return max({1+hL+hR, d(root->left), d(root->right)});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return d(root)-1;
    }
};
