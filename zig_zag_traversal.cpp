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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        s1.push(root);
        vector<vector<int>> ans;
        if(!root) return ans;
        while(!(s1.empty() && s2.empty())) {
            vector<int> t;
            while(!s1.empty()) {
                TreeNode* top = s1.top(); s1.pop();
                t.push_back(top->val);
                if(top->left) s2.push(top->left);
                if(top->right) s2.push(top->right);
            }
            if(t.size()) {
                ans.push_back(t);
                t.clear();   
            }
            while(!s2.empty()) {
                TreeNode* top1 = s2.top(); s2.pop();
                t.push_back(top1->val);
                if(top1->right) s1.push(top1->right);
                if(top1->left) s1.push(top1->left);
            }
            if(t.size()) {
                ans.push_back(t);
                t.clear();   
            }
        }
        return ans;
    }
};
