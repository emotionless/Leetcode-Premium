class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[0][i]) {
                for (int j = n-1; j > 0; j--) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += grid[i][j];
            }
            if (cnt == 0 || cnt == m) continue;
            return false;
        }
        return true;
    }
};