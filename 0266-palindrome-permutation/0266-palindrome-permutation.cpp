// solved by Milon
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<26> cnt;
        for (auto &ch : s) {
            cnt.flip(ch-'a');
        }
        return cnt.count() <= 1;
    }
};