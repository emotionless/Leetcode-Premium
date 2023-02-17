// solved by Milon
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, set<int>> mp;
        int mn = INT_MAX, mx = INT_MIN;
        for (auto &point : points) {
            mn = min(mn, point[0]);
            mx = max(mx, point[0]);
            mp[point[1]].insert(point[0]);
        }
        double line = (mn + mx) / 2.0;
        for (auto v : mp) {
            auto &cur = v.second;
            for (auto st = cur.begin(), ed = cur.end(); st != ed; st++) {
                if ((*st + *(--ed)) / 2.0 != line) {
                    return false;
                }
                if (st == ed) break;
            }
        }
        return true;
    }
};