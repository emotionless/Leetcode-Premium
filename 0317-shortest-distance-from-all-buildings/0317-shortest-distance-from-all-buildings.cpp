// solved by Milon

class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    
    void shortestDistance(const vector<vector<int>> &grid, int x, int y) {
        queue<pair<pair<int, int>, int>> q;
        bool vis[n][m];
        memset(vis, false, sizeof vis);
        
        q.push(make_pair(make_pair(x, y), 0));
        
        vis[x][y] = true;
        while(!q.empty()) {
            pair<pair<int, int>, int> top = q.front();
            q.pop();
            int cx = top.first.first;
            int cy = top.first.second;
            int cc = top.second;
            cost[cx][cy] += cc;
            cnt[cx][cy]++;
            
            
            for(int i = 0; i < 4; i++) {
                int ax = cx + dr[i];
                int ay = cy + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || vis[ax][ay] || grid[ax][ay] != 0) continue;
                vis[ax][ay] = true;
                q.push(make_pair(make_pair(ax, ay), cc + 1));
            }
        }
        return;
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        cnt.resize(n, vector<int>(m, 0));
        cost.resize(n, vector<int>(m, 0));
        int res = INT_MAX;
        int tot = 0;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    tot++;
                    shortestDistance(grid, i, j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                   if (cnt[i][j] == tot) {
                       res = min(res, cost[i][j]);
                   }
                }
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
private:
    vector<vector<int>> cnt, cost;
    int n, m;
};