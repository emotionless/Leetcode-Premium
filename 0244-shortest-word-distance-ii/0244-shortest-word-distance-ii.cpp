// solved by Milon

class WordDistance {
public:
    const int INF = 100000000;
    
    WordDistance(vector<string>& wordsDict) {
        int sz = wordsDict.size();
        for (int i = 0; i < sz; i++) {
            container[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto word1PosList = container[word1];
        auto word2PosList = container[word2];
        int i = 0, j = 0;
        int sz1 = word1PosList.size();
        int sz2 = word2PosList.size();
        int ans = INF;
        while (i < sz1 && j < sz2) {
            ans = min(ans, abs(word1PosList[i] - word2PosList[j]));
            if (word1PosList[i] < word2PosList[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
private:
    unordered_map<string, vector<int>> container;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */