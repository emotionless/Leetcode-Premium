class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int mx = mn + n - 1;
        for (auto &v : nums) {
            int num = abs(v);
            if (num > mx) return false;
            nums[num - mn] *= -1;
        }
        int cnt = 0;
        for (auto &v : nums) {
            if (v == 0) {
                cnt++;
                continue;
            }
            if (v > 0) return false;
        }
        if (cnt > 1) return false; 
        return true;
    }
};