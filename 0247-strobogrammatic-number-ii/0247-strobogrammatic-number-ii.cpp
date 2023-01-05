class Solution {
public:
    
    void solve(int st, int ed, string str) {
        if (st > ed) {
            ans.push_back(str);
            return;
        }
        for (auto it : mp) {
            if (st == 0 && it.first == '0') continue;
            if (st == ed && (it.first == '6' || it.first == '9')) continue;
            string tmp = str;
            tmp[st] = it.first;
            tmp[ed] = it.second;
            solve(st + 1, ed - 1, tmp);
        }
        
        return;
    }
    
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) return {"1", "0", "8"};
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        string str;
        str.resize(n);
        ans.clear();
        solve(0, n-1, str);
        return ans;
    }
private:
    vector<string> ans;
    unordered_map<char, char> mp;

};