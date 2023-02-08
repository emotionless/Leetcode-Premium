// solved by Milon

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rowMove.resize(n, vector<int>(2, 0));
        colMove.resize(n, vector<int>(2, 0));
        diagLMove = diagRMove = 0;
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        player--;
        rowMove[row][player]++;
        if (rowMove[row][player] == N) return player + 1;
        colMove[col][player]++;
        if (colMove[col][player] == N) return player + 1;
        if (row == col) {
            diagLMove += (player == 0? 1 : -1);
            if (abs(diagLMove) == N) return player + 1;
        }
        if ((row + col) == (N - 1)) {
            diagRMove += (player == 0? 1 : -1);
            if (abs(diagRMove) == N) return player + 1;
        }
        return 0;
    }
private:
    int N;
    vector<vector<int>> rowMove, colMove;
    int diagLMove, diagRMove;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */