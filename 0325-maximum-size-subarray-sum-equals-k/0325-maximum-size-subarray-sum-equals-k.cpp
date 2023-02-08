// solved by Milon
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> pos;
        pos[0] = -1;
        int sz = nums.size();
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
            if (pos.find(sum - k) != pos.end()) {
                ans = max(ans, i - pos[sum - k]);
            }
            if (pos.find(sum) == pos.end()) {
                pos[sum] = i;
            }
        }
        return ans;
    }
};