// solved by Milon

class Solution {
public:
    const int base = 31;
    const int MOD = 1e9 + 7;
    
    string makeHash(int a, int b) {
        return to_string(a) + "#" + to_string(b);
    }
    
    bool differByOne(vector<string>& dict) {
        unordered_set<string> visited;
        int len = dict[0].size();
        vector<int> hash(len + 1, -1);
        for (const auto &word : dict) {
            long long sum = 0;
            for (int i = len - 1; i >= 0; i--) {
                sum = (sum * base + (word[i] - 'a'))%MOD;
                hash[i] = sum;
            }
            sum = 0;
            for (int i = 0; i < len; i++) {
                string p = makeHash(sum, hash[i + 1]);
                if (visited.find(p) != visited.end()) {
                    return true;
                }
                visited.insert(p);
                sum = (sum * base + (word[i] - 'a')) % MOD;
            }
        }
        return false;
    }
};