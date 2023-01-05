// solved by Milon
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int len = s.size();
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j < len && s[j] != ' ') {
                j++;
            }
            int sz = j - i;
            reverse(s.begin() + i, s.begin() + i + sz);
            i = j;
        }
    }
};