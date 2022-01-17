// solved by Milon

class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> even, odd;
        for (auto x : nums) {
            if (x&1) odd.push_back(x);
            else even.push_back(x);
        }
        sort(even.begin(), even.end());
        reverse(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        
        int eSize = even.size();
        int oSize = odd.size();
        
        for (int i = 1; i < oSize; i++) {
            odd[i] += odd[i-1];
        }
        long long ans = -1, sum = 0;
        if (k <= oSize && odd[k-1]%2==0) {
            ans = odd[k-1];
        }
        for (int i = 0; i < k && i < eSize; i++) {
            sum += even[i];
            int rest = k - i - 1;
            if (rest == 0) {
                ans = max(ans, sum);
                continue;
            }
            if (rest <= oSize) {
                long long total = sum + odd[rest - 1];
                if (total%2==0) {
                    ans = max(ans, total);
                }
            }
        }
        return ans;
    }
};