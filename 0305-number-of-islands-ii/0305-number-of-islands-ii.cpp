// solved by Milon
class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int find(int x) {
        if (par.find(x) == par.end()) return -1;
        else if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        int cnt = 0;
        vector<int> ans;
        for (auto &pos : positions) {
            int x = pos[0];
            int y = pos[1];
            int cur = x*m + y;
            if (find(cur) != -1) {
                ans.push_back(cnt);
                continue;
            }
            par[cur] = cur;
            for (int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m) continue;
                int id = ax*m + ay;
                int p = find(id);
                // cout << cur << " " << id << " " << p << endl;
                if (p != -1 && p != cur) {
                    par[p] = cur;
                    // cout << p << " " << cur << endl;
                    cnt--;
                }
            }
            cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
private:
    unordered_map<int, int> par;
};