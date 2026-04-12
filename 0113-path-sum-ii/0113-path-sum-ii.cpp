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
private:
    void path(TreeNode* root, int targetsum, int sum, vector<int>& curr, vector<vector<int>>& ans){
        sum += root->val;
        curr.push_back(root->val);
        if(!root->left && !root->right && sum==targetsum){
            ans.push_back(curr);
        }
        if(root->left){
            path(root->left, targetsum, sum, curr, ans);
        }
        if(root->right){
            path(root->right, targetsum, sum, curr, ans);
        }
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currpath;
        if (!root) return ans;
        path(root, targetSum, 0, currpath, ans);
        return ans;
    }
};