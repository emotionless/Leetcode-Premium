// solved by Milon
class Solution {
public:
    bool check = true;
    
    pair<int, int> solve(int st, int ed, const vector<int> &preorder) {
        if (st == ed) return {preorder[st], preorder[st]};
        int mn = preorder[st], mx = preorder[st];
        
        for (int i = st + 1; i <= ed; i++) {
            if (preorder[i] > preorder[st]) {
                if ((st + 1) < i) {    
                    auto leftChild = solve(st + 1, i - 1, preorder);
                    if (leftChild.second > preorder[st] || leftChild.first > preorder[st]) check = false;
                    mn = min(mn, leftChild.first);
                    mx = max(leftChild.second, mx);
                }
                auto rightChild = solve(i, ed, preorder);
                if (rightChild.first < preorder[st] || rightChild.second < preorder[st]) check = false;
                mn = min(mn, rightChild.first);
                mx = max(rightChild.second, mx);
                break;
            }
        }
        if (mn == preorder[st] && mx == preorder[st]) {
            auto leftChild = solve(st + 1, ed, preorder);
            if (leftChild.second > preorder[st] || leftChild.first > preorder[st]) check = false;
            mn = min(mn, leftChild.first);
            mx = max(leftChild.second, mx);
        }
        // cout << st << " " << ed << " " << mn << " " << mx << endl;
        return {mn, mx};
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        // solve(0, preorder.size() - 1, preorder);
        // return check;
        int n = preorder.size();
        if (n <= 2) return true;
        int last = INT_MIN;
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            int cur = preorder[i];
            if (s.empty() || cur < s.top()) {
                if (cur < last) return false;
            } else {
                while (!s.empty() && cur > s.top()) {
                    last = s.top();
                    s.pop();
                }
            }
            s.push(cur);
        }
        
        return true;
    }
};