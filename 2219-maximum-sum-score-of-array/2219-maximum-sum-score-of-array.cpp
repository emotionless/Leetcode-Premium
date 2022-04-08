class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long rightSum = 0;
        for (auto &v : nums) rightSum += v;
        long long leftSum = 0, ans = nums[0];
        for (auto &v : nums) {
            leftSum += v;
            ans = max(ans, max(leftSum, rightSum));
            rightSum -= v;
        }
        return ans;
    }
};