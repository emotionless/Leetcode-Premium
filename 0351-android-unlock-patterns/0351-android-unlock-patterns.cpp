// solved by Milon

class Solution {
public:
    
    bool isSet(int mask, int bt) {
        return mask&(1<<bt);
    }
    
    bool isValid(int mask, int cur, int nxt) {
        int b = mask&(1<<5);
        if ((cur + nxt) == 10) {
            return b;
        }
        if (cur == 1) {
            if (nxt == 7 && !isSet(mask, 4)) return false;
            if (nxt == 3 && !isSet(mask, 2)) return false;
            return true;
        }
        if (cur == 3) {
            if (nxt == 1 && !isSet(mask, 2)) return false;
            if (nxt == 9 && !isSet(mask, 6)) return false;
            return true;
        }
        if (cur == 7) {
            if (nxt == 1 && !isSet(mask, 4)) return false;
            if (nxt == 9 && !isSet(mask, 8)) return false;
            return true;
        }
        if (cur == 9) {
            if (nxt == 7 && !isSet(mask, 8)) return false;
            if (nxt == 3 && !isSet(mask, 6)) return false;
            return true;
        }
        return true;
    }
    
    int solve(int mask, int cur, int remaining) {
        if (remaining == 0) {
            return 1;
        }
        int &ret = dp[mask][cur];
        
        if (ret != -1) return ret;
        ret = 0;
        for (int i = 1; i < 10; i++) {
            if (!isSet(mask, i) && isValid(mask, cur, i)) {
                ret += solve(mask|(1<<i), i, remaining - 1);
            }
        }
        return ret;
    }
    
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        for (int i = m; i <= n; i++) {
            dp.clear();
            dp.resize(1<<12, vector<int>(10, -1));
            for (int j = 1; j < 10; j++) {
                ans += solve(1<<j, j, i - 1);
            }
        }
        return ans;
    }
private:
    vector<vector<int>> dp;
};