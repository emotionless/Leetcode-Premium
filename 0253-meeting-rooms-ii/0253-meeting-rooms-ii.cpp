// solved by Milon
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        unordered_map<int, int> counter;
        set<int> nums;
        for (auto interval : intervals) {
            counter[interval[0]]++;
            counter[interval[1]]--;
            nums.insert(interval[0]);
            nums.insert(interval[1]);
        }
        int cnt = 0;
        int mx = 0;
        for (auto v : nums) {
            cnt += counter[v];
            mx = max(mx, cnt);
        }
        return mx;
    }
};