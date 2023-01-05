class Solution {
public:
    
    bool isStrobogrammatic(string num) {
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        string str = "";
        for (auto &ch : num)  {
            if (mp.find(ch) == mp.end()) return false;
            str = mp[ch] + str;
        }
        return num == str;
    }
private:
    unordered_map<char, char> mp;
};