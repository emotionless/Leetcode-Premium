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
    
    tuple<int, int, int> getLargestBST(TreeNode *cur) {
        if (cur == nullptr) {
            return {INT_MAX, INT_MIN, 0};
        }
        auto l = getLargestBST(cur->left);
        auto r = getLargestBST(cur->right);
        if (get<1>(l) < cur->val && cur->val < get<0>(r)) {
            return {min(get<0>(l), cur->val), max(get<1>(r), cur->val), 1 + get<2>(l) + get<2>(r)};
        } else {
            return {INT_MIN, INT_MAX, max(get<2>(l), get<2>(r))};
        }
    }
    
    int largestBSTSubtree(TreeNode* root) {
        return get<2>(getLargestBST(root));
    }
};