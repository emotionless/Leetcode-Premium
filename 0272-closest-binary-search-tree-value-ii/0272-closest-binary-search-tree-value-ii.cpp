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
    
    void preOrder(TreeNode *cur, vector<int> &nums) {
        if (cur == nullptr) return;
        preOrder(cur->left, nums);
        nums.push_back(cur->val);
        preOrder(cur->right, nums);
        
        return;
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {    
        vector<int> nums;
        preOrder(root, nums);
        int n = nums.size();
        int pos = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > target) {
                pos = i;
                break;
            }
        }
        int pre = pos - 1;
        if (pre == -1) {
            nums.resize(k);
            return nums;
        }
        vector<int> ans;
        while (k--) {
            if (pre == -1) {
                ans.push_back(nums[pos++]);
                continue;
            }
            if (pos == n) {
                ans.push_back(nums[pre--]);
                continue;
            }
            if (fabs(nums[pre] - target) < fabs(nums[pos] - target)) {
                ans.push_back(nums[pre--]);
            } else {
                ans.push_back(nums[pos++]);
            }
        }
        return ans;
    }
private:
};