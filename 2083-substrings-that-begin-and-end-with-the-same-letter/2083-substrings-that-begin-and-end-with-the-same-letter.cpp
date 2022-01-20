// solved by Milon

class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, long long> degree;
        for (auto ch : s) {
            degree[ch]++;
        }
        long long ans = 0;
        for (auto it : degree) {
            ans += (it.second*(it.second + 1ll))/2ll;
        }
        return ans;
    }
};