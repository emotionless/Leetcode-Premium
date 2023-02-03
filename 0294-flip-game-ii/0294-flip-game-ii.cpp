// solved by Milon
class Solution {
public:
    bool canWin(string currentState) {
        if (currentState.size() <= 1) return false;
        
        for (int i = 0; i < currentState.size() - 1; i++) {
            if (currentState[i] == '+' && currentState[i+1] == '+') {
                string str = currentState;
                str[i] = str[i+1] = '-';
                if (!canWin(str)) {
                    return true;
                }
            }
        }
        return false;
    }
};