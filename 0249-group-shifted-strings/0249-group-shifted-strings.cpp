// solved by Milon
class Solution {
public:
    
    string shiftString(string str) {
        int len = str.size();
        int dist = str[0] - 'a';
        for (auto &ch : str) {
            ch = (char)((ch - 'a' - dist + 26) % 26 + 'a');
        }
        return str;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto &str : strings) {
            string shiftedStr = shiftString(str);
            mp[shiftedStr].push_back(str);
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};