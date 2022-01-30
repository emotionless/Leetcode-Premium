// solved by Milon

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int solve(int ind, const int sum, vector<int> &nums1, vector<int> &nums2) {
        int &ret = dp[ind][sum + 10000];
        if (ret != -1) return ret;
        ret = 0;
        if (sum == 0) {
            ret = 1;
        }
        if (ind == nums1.size()) {
            return ret;
        }
        ret = (ret + solve(ind + 1, sum + nums1[ind], nums1, nums2)) % MOD;
        ret = (ret + solve(ind + 1, sum - nums2[ind], nums1, nums2)) % MOD;
        return ret;
    }
    
    int countSubranges(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        int n = nums1.size();
        dp.resize(n + 1, vector<int>(20009, -1));
        for (int i = n - 1; i >= 0; i--) {
            ret = (ret + solve(i + 1, nums1[i], nums1, nums2)) % MOD;
            ret = (ret + solve(i + 1, -nums2[i], nums1, nums2)) % MOD;
        }
        return ret;
    }
private:
    vector<vector<int>> dp;
};

/*

[1,2,5,3,4,5,7,5,3,2,1,1,3]
[2,6,3,3,5,6,7,4,2,2,1,1,4]

*/