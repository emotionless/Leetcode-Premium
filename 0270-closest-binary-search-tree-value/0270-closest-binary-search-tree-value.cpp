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
    void dfs(TreeNode *cur, double tar) {
        if (cur == nullptr) return;
        if (abs(cur->val - tar) < dif) {
            dif = abs(cur->val - tar);
            ans = cur;
        }
        if (tar > cur->val) dfs(cur->right, tar);
        else dfs(cur->left, tar);
    }
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return ans->val;
    }
private:
    double dif = INT_MAX;
    TreeNode *ans = nullptr;
};