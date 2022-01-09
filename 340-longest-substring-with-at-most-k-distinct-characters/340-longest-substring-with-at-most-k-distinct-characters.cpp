// solved by Milon

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(const string s, int k) {
        int len = s.length();
        int j = 0;
        if (!k) return 0;
        int ans = 0;
        unordered_map<char, int> counter;
        for(int i = 0; i < len; i++) {
            // if (j < i) {
            //     counter.clear();
            //     j = i;
            // }
            while(j < len && (counter.size() < k || counter.find(s[j]) != counter.end())) {
                counter[s[j]]++;
                j++;
            }
            // cout << i << " " << j << " " << counter.size() << endl;
            // if (j == len)
            ans = max(ans, j - i);
            // else
            //     ans = max(ans, j - i - 1);
            counter[s[i]]--;
            if (counter[s[i]] == 0) {
                counter.erase(s[i]);
            }
        }
        return ans;
    }
};