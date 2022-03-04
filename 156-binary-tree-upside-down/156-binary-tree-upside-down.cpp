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
    
    void upsideDown(TreeNode *cur, TreeNode *par) {
        if (cur == nullptr) return;
        upsideDown(cur->left, cur);
        if (cur->left == nullptr && cur->right == nullptr) {
            ans = cur;
        }
        cur-> left = par->right;
        cur->right = par;
        
        return;
    }
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr) return root;
        upsideDown(root->left, root);
        root->left = root->right = nullptr;
        return ans;
    }
private:
    TreeNode *ans = nullptr;
};