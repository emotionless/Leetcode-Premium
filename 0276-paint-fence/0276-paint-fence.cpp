// Milon
class Solution {
public:
    
    int solve(int ind) {
        if (ind == 1) {
            return numOfCol;
        } else if (ind == 2) {
            return numOfCol * numOfCol;
        }
        int &ret = dp[ind];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        ret = solve(ind - 1) * (numOfCol - 1);
        ret += solve(ind - 2) * (numOfCol - 1);
        return ret;
    }
    
    int numWays(int n, int k) {
        numOfCol = k;
        if (n == 1) {
            return k;
        }
        dp.clear();
        dp.resize(3, 0);
        dp[0] = k;
        dp[1] = k*k;
        for (int i = 2; i < n; i++) {
            dp[i%3] = dp[(i-1)%3] * (k - 1);
            dp[i%3] += dp[(i-2)%3] * (k - 1);
        }
        return dp[(n-1)%3];
    }
private:
    int numOfCol;
    vector<int> dp;
};