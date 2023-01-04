class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int a = INT_MAX, b = INT_MAX;
        int ans = INT_MAX;
        for (int i = 0; i < wordsDict.size(); i++) {
            if (word1 == wordsDict[i]) {
                a = i;
                ans = min(ans, abs(a - b));
            } else if (word2 == wordsDict[i]) {
                b = i;
                ans = min(ans, abs(a - b));
            }
        }
        return ans;
    }
};