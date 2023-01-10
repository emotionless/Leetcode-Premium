// solve by Milon
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                int mn = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    if ((i+1) == n) continue;
                    mn = min(mn, dp[i+1][k]);
                }
                dp[i][j] = (mn == INT_MAX? 0 : mn) + costs[i][j];
            }
        }
        return min(dp[0][0], min(dp[0][1], dp[0][2]));
    }
};