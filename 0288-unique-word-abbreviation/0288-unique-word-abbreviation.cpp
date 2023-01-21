// solved by Milon
class ValidWordAbbr {
public:
    string getAbbr(string &str) {
        int len = str.size();
        if (len <= 2) return str;
        return str[0] + to_string(len - 2) + str[len - 1];
    }
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto &str : dictionary) {
            mp[getAbbr(str)].insert(str);
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        if (mp.find(abbr) == mp.end()) return true;
        auto &words = mp[abbr];
        if (words.size() > 1) return false;
        return *words.begin() == word;
    }
private:
    unordered_map<string, unordered_set<string>> mp;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */