// solved by Milon

class Solution {
public:
    string convertToString(int a, int b) {
        if (a == b) return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int pre = lower - 1;
        vector<string> ans;
        for (auto num : nums) {
            int st = pre + 1;
            int ed = num - 1;
            if (ed >= st) {
                ans.push_back(convertToString(st, ed));
            }
            pre = num;
        }
        if (pre + 1 <= upper) {
            ans.push_back(convertToString(pre + 1, upper));
        }
        return ans;
    }
};