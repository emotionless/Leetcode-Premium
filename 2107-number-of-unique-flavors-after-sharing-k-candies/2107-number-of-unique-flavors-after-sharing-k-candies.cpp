// solved by Milon

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int n = candies.size();
        unordered_map<int, int> counter;
        for (auto candy : candies) {
            counter[candy]++;
        }
        int total = counter.size();
        int answer = 0;
        for (int i = 0; i < n; i++) {
            counter[candies[i]]--;
            if (counter[candies[i]] == 0) {
                total--;
            }
            if (i >= k) {
                int last = candies[i - k];
                counter[last]++;
                if (counter[last] == 1) {
                    total++;
                }
                answer = max(answer, total);
            } else if (i == (k-1)) {
                answer = max(answer, total);
            }
        }
        return answer;
    }
};