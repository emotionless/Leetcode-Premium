// Milon

class Solution {
public:
    
    bool solve(int ind1, int ind2, const string pattern, const string s, unordered_map<char, string> hash, unordered_set<string> visited) {
        if (ind1 == pattern.length() || ind2 == s.length()) {
            return ind1 == pattern.length() && ind2 == s.length();
        }
        if (ind1 >= pattern.length() || ind2 >= s.length()) {
            return false;
        }
        int &ret = dp[ind1][ind2];
        //if (ret != -1) return ret;
        ret = 0;
        char ch = pattern[ind1];
        if (hash.find(ch) == hash.end()) {
            string str = "";
            for (int i = ind2; i < s.length(); i++) {
                str += s[i];
                if (visited.find(str) == visited.end()) {
                    visited.insert(str);
                    hash[ch] = str;
                    ret += solve(ind1 + 1, i + 1, pattern, s, hash, visited);
                    if (ret > 0) return ret;
                    hash.erase(ch);
                    visited.erase(str);
                }
            }
        } else {
            int sz = hash[ch].size();
            string str = s.substr(ind2, sz);
            if (str == hash[ch]) {
                ret += solve(ind1 + 1, ind2 + sz, pattern, s, hash, visited);
            }
        }
        auto p = hash[ch]; 
        // cout << ind1 << " " << ind2 << " " << p << " " << ret << endl;
        return ret;
    }
    
    
    
    bool wordPatternMatch(string pattern, string s) {
        if (pattern.size() == 1) return true;
        dp.resize(pattern.size(), vector<int>(s.length(), -1));
        unordered_map<char, string> hash;
        unordered_set<string> visited;
        return solve(0, 0, pattern, s, hash, visited);
    }
private:
    vector<vector<int>> dp;
};