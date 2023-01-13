// solved by Milon
class Solution {
public:
    const int INF = 10000;
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int m = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
        vector<int> curCost(m, 0), right(m, 0), left(m, 0);
        int res = INF;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                curCost[j] = costs[i][j] + dp[i+1][j];
            }
            right[m-1] = curCost[m-1];
            for (int j = m - 2; j >= 0; j--) {
                right[j] = min(curCost[j], right[j + 1]);
            }
            left[0] = curCost[0];
            for (int j = 1; j < m; j++) {
                left[j] = min(curCost[j], left[j-1]);
            }
            int pre = INF;
            for (int j = 1; j < m-1; j++) {
                dp[i][j] = min(left[j-1], right[j+1]);
            }
            dp[i][0] = right[1];
            dp[i][m-1] = left[m-2];
            // for (int j = 0; j < m; j++) cout << dp[i][j] << " ";
            // cout << endl;
        }
        for (int j = 0; j < m; j++) res = min(res, dp[0][j]);
        return res;
    }
};