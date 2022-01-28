// solved by Milon
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        unordered_map<int, unordered_set<int>> container;
        for (auto &cor : corridors) {
            if (cor[0] > cor[1]) swap(cor[0], cor[1]);
            container[cor[0]].insert(cor[1]);
        }
        int cnt = 0;
        for (auto &cor : corridors) {
            int u = cor[0];
            int v = cor[1];
            auto &uSet = container[u];
            auto &vSet = container[v];
            for (auto &num : uSet) {
                if (vSet.find(num) != vSet.end()) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};