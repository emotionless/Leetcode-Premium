// solved by Milon

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int n = candies.size();
        unordered_map<int, int> counter;
        for (auto candy : candies) {
            counter[candy]++;
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            counter[candies[i]]--;
            if (counter[candies[i]] == 0) {
                counter.erase(candies[i]);
            }
            if (i >= k) {
                int last = candies[i - k];
                counter[last]++;
            }
            if ((i+1) >= k) {
                answer = max(answer, (int)counter.size());
            }
        }
        return answer;
    }
};