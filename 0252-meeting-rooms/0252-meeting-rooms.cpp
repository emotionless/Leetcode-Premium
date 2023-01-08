// Solved by Milon

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int pre = 0;
        for (auto &cur : intervals) {
            if (cur[0] < pre) return false;
            pre = cur[1];
        }
        return true;
    }
};