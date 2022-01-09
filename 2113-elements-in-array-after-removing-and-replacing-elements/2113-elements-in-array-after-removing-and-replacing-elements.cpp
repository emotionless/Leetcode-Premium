class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int tot = n * 2;
        vector<int> res;
        for (auto query : queries) {
            int time = query[0] % tot;
            int ind = query[1];
            int ans = -1;
            if (time == n) {
                ans = -1;
            } else if (time < n) {
                ans = (time + ind) < n? nums[time + ind] : -1;
            } else {
                ans = (time - n) > ind? nums[ind] : -1;
            }
            res.push_back(ans);
        }
        return res;
    }
};