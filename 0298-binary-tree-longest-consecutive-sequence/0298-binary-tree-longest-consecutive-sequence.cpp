// solved by Milon

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
    void dfs(TreeNode *cur, int counter, int pre, int &ans) {
        if (cur == nullptr) {
            return;
        }
        if (cur->val == (pre + 1)) {
            counter++;
        } else {
            counter = 1;
        }
        ans = max(ans, counter);
        dfs(cur->left, counter, cur->val, ans);
        dfs(cur->right, counter, cur->val, ans);
        
        return;
    }
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        if (root == nullptr) return ans;
        dfs(root, 0, root->val, ans);
        return ans;
    }
};