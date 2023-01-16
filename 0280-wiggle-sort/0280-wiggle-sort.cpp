// solved by Milon

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (i&1) {  // >=
                if (nums[i] < nums[i-1]) {
                    swap(nums[i], nums[i-1]);
                }
            } else {    // <=
                if (nums[i] > nums[i-1]) {
                    swap(nums[i], nums[i-1]);
                }
            }
        }
        return;
    }
};