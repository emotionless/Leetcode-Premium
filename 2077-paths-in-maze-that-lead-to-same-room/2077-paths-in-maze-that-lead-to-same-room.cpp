class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        matrix.resize(n, vector<bool>(n, false));
        for (auto &cor : corridors) {
            if (cor[0] > cor[1]) swap(cor[0], cor[1]);
            matrix[cor[0] - 1][cor[1] - 1] = true;
            // matrix[cor[1] - 1][cor[0] - 1] = true;
        }
        int cnt = 0;
        for (auto cor : corridors) {
            int u = cor[0] - 1;
            int v = cor[1] - 1;
            for (int k = 0; k < n; k++) {
                if (matrix[u][k] && matrix[v][k]) {
                    cnt++;
                }
            }
            //cout << cnt << endl;
        }
        return cnt;
    }
private:
    vector<vector<bool>> matrix;
};