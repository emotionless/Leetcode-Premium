// solved by Milon

class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }
        
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            
            int c = top.first;
            int x = top.second.first;
            int y = top.second.second;
            for (int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || rooms[ax][ay] == -1 || vis[ax][ay]) continue;
                rooms[ax][ay] = c + 1;
                vis[ax][ay] = true;
                q.push({c + 1, {ax, ay}});
            }
        }
    }
private:
    vector<vector<bool>> vis;
};