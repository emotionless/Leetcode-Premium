// solved by Milon
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) return 0;
        int mid = (nums[n/2] + nums[(n-1)/2])/2;
        long long ans = 0;
        for (auto &num : nums) {
            ans += abs(num - mid);
        }
        return ans;
    }
};