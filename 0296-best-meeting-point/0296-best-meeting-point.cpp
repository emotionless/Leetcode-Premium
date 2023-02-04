// solved by Milon
class Solution {
public:
    
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> allX, allY;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    allX.push_back(i);
                    allY.push_back(j);
                }
            }
        }
        int sz = allX.size();
        sort(allX.begin(), allX.end());
        sort(allY.begin(), allY.end());
        int midX = allX[sz/2];
        int midY = allY[sz/2];
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            ans += abs(allX[i] - midX) + abs(allY[i] - midY);
        }
        return ans;
    }
};