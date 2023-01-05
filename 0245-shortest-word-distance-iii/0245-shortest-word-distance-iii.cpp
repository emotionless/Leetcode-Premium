// solved by Milon

class Solution {
public:
    const int INF = 100000000;
    
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int word1Pos = -INF;
        int word2Pos = -INF;
        int sz = wordsDict.size();
        int ans = INF;
        for (int i = 0; i < sz; i++) {
            if (wordsDict[i] == word1) {
                ans = min(ans, i - word2Pos);
                word1Pos = i;
            }
            if (wordsDict[i] == word2) {
                if (word1Pos != i)
                    ans = min(ans, i - word1Pos);
                word2Pos = i;
            }
        }
        return ans;
    }
};