class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        matrix.resize(n, vector<bool>(n, false));
        for (auto cor : corridors) {
            matrix[cor[0] - 1][cor[1] - 1] = true;
            matrix[cor[1] - 1][cor[0] - 1] = true;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!matrix[i][j]) continue;
                for (int k = j + 1; k < n; k++) {
                    if (matrix[j][k] && matrix[i][k]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
private:
    vector<vector<bool>> matrix;
};