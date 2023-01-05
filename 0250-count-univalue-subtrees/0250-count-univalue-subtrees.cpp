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
    
    bool solve(const TreeNode *cur, int &ans) {
        if (cur == nullptr) return true;
        bool okay = solve(cur -> left, ans) & solve(cur -> right, ans);
        if (cur->left && cur->left -> val != cur->val) okay = false;
        if (cur->right && cur->right -> val != cur->val) okay = false;
        
        if (okay) ans++;
        return okay;
    }
    
    int countUnivalSubtrees(const TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};