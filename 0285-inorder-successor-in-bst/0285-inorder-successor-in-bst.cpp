// solved by Milon
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//     void traverse(TreeNode *cur, TreeNode *p) {
//         if (cur == nullptr) return;
//         traverse(cur->right, p);
//         if (cur == p) {
//             // cout << last->val << endl;
//             ans = last;
//             return;
//         }
//         last = cur;
//         traverse(cur->left, p);
        
//     }
    
    void traverse(TreeNode *cur, int p) {
        if (cur == nullptr) return;
        if (p > cur->val) {
            traverse(cur->right, p);
        } else {
            ans = cur;
            traverse(cur->left, p);
        }
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *last = nullptr;
        traverse(root, p->val + 1);
        return ans;
    }
private:
    TreeNode *ans = nullptr, *last = nullptr;
};