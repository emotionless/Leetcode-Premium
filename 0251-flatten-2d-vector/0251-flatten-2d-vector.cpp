// solved by Milon

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) {
        int n = vec.size();
        for (int i = n - 1; i >= 0; i--) {
            stk.push(vec[i].end());
            stk.push(vec[i].begin());
        }
    }
    
    int next() {
        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if (top == stk.top()) stk.pop();
            else {
                int v = *top;
                top++;
                stk.push(top);
                return v;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if (top == stk.top()) stk.pop();
            else {
                stk.push(top);
                return true;
            }
        }
        return false;
    }
private:
    stack<vector<int>::iterator> stk;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */