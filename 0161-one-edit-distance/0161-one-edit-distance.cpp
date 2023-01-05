// solved by Milon
class Solution {
public:
    bool isOneEditDist(const string s, const string t) {
        if ((t.length() - s.length()) != 1) return false;
        int len = s.length();
        int j = 0;
        for (int i = 0; i < t.length() && j < len; i++) {
            if (t[i] != s[j]) {
                if (i != j) return false;
            } else {
                j++;
            }
        }
        return j == len;
    }
    bool isOneEditDistance(string s, string t) {
        if (isOneEditDist(s, t) || isOneEditDist(t, s)) return true;
        if (s.length() != t.length()) return false;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) cnt++;
        }
        return cnt == 1;
    }
};