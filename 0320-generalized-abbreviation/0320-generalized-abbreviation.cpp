// Solved by Milon
class Solution {
public:
    vector<string> generate(int index, bool isWord, const string &word) {
        if (index == word.size()) {
            return {""};
        }
        if (dp.find(make_pair(index, isWord)) != dp.end()) {
            return dp[make_pair(index, isWord)];
        }
        vector<string> &ret = dp[make_pair(index, isWord)];
        if (isWord) {
            string str = "";
            for (int i = index; i < word.size(); i++) {
                str += word[i];
                auto wordList = generate(i + 1, false, word);
                for (auto ele : wordList) {
                    ret.push_back(str + ele);
                }
            }
        } else {
            for (int i = index; i < word.size(); i++) {
                auto wordList = generate(i + 1, true, word);
                for (auto ele : wordList) {
                    ret.push_back(to_string(i - index + 1) + ele);
                }
            }
        }
        return ret;
    }
    
    vector<string> generateAbbreviations(string word) {
        auto res = generate(0, false, word);
        vector<string> ret;
        ret = res;
        res = generate(0, true, word);
        for (auto ele : res) {
            ret.push_back(ele);
        }
        return ret;
    }
private:
    map<pair<int, bool>, vector<string>> dp;
};