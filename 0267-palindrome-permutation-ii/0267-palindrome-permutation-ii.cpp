// solved by Milon

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> counter;
        for (auto ch : s) {
            counter[ch]++;
        }
        string str = "";
        int odd = 0;
        char extra = ' ';
        for (auto ele : counter) {
            if (ele.second % 2 == 1) {
                odd++;
                extra = ele.first;
            }
            for (int i = 0; i < ele.second/2; i++) {
                str += (ele.first);
            }
        }
        if (odd > 1) return {};
        sort(str.begin(), str.end());
        vector<string> ans;
        string tmp = "";
        if (odd) tmp += extra;
        do {
            string rev = str;
            reverse(rev.begin(), rev.end());
            string now = str + tmp + rev;
            ans.push_back(now);
        } while (next_permutation(str.begin(), str.end()));
        
        return ans;
    }
};