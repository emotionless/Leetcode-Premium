// solved by Milon

class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lastEven = -1, lastOdd = -1;
        long long sum = 0;
        for (int i = n - 1; i >= (n - k); i--) {
            sum += nums[i];
            if (nums[i]&1) {
                lastOdd = nums[i];
            } else {
                lastEven = nums[i];
            }
        }
        if (sum %2 == 0) return sum;
        long long ans = -1;
        for (int i = 0; i < n-k; i++) {
            if (nums[i]%2 == 1 && (lastEven != -1)) {
                ans = max(ans, sum - lastEven + nums[i]);
            } else if (nums[i] % 2 == 0 && lastOdd != -1) {
                ans = max(ans, sum - lastOdd + nums[i]);
            }
        }
        return ans;
    }
};