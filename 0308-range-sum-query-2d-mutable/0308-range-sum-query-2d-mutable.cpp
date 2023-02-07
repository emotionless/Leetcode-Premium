// solved by Milon
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return;
        m = matrix[0].size();

        sum.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum[i][j] = matrix[i][j] + (j?sum[i][j-1] : 0);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int dif = (col == 0? val - sum[row][col] : val - sum[row][col] + sum[row][col-1]);
        for(int i = col; i < m; i++) {
            sum[row][i] += dif;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++) {
            ans += sum[i][col2] - (col1?sum[i][col1-1] : 0);
        }
        return ans;
    }
private:
    int n, m;
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */