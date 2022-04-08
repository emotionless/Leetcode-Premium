// solved by Milon
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.length();
        unordered_map<char, int> counter;
        int tot = 0;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            counter[s[i]]++;
            if (counter[s[i]] == 1) {
                tot++;
            }
            while (j < i && tot > 2) {
                counter[s[j]]--;
                if (counter[s[j]] == 0) tot--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};