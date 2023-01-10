// solved by Milon
class Solution {
public:
    
    vector<vector<int>> solve(int n, int st) {
        int sq = sqrt(n);
        vector<vector<int>> ret;
        for (int i = st; i <= sq; i++) {
            if (n%i == 0) {
                auto tmp = solve(n/i, i);
                for (auto v : tmp) {
                    v.push_back(i);
                    ret.push_back(v);
                }
            }
        }
        ret.push_back({n});
        return ret;
    }
    
    vector<vector<int>> getFactors(int n) {
        auto res = solve(n, 2);
        res.pop_back();
        return res;
    }
};

/*

12
2 6{2, 3}
3 4

*/