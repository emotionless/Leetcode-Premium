// solved by Milon

class Solution {
public:
    
    bool isPossible(const long long &tar, int armor, vector<int> &damage) {
        int n = damage.size();
        int mx = 0;
        long long val = tar;
        for (auto &v : damage) {
            mx = max(mx, v);
            if (v > val && armor > 0) {
                val += min(armor, mx);
                armor = 0;
            }
            val -= v;
        }
        if (armor) val += armor;
        return val > 0;
    }
    
    long long minimumHealth(vector<int>& damage, int armor) {
        long long st = 1, ed = 1e10 + 20, ans = -1;
        while (st <= ed) {
            auto mid = (st + ed) / 2;
            if (isPossible(mid, armor, damage)) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};