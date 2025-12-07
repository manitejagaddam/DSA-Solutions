class Solution {
public:
    int sum = 0;

    void dfs(int i, int j, vector<vector<char>>& b, char ch) {
        if (i < 0 || j < 0 || i >= 8 || j >= 8 || b[i][j] == 'B') return;

        if (b[i][j] == 'p') {
            sum++;
            return;
        }

        if (ch == 'L') dfs(i, j - 1, b, 'L');
        if (ch == 'R') dfs(i, j + 1, b, 'R');
        if (ch == 'U') dfs(i - 1, j, b, 'U');
        if (ch == 'D') dfs(i + 1, j, b, 'D');
    }

    int numRookCaptures(vector<vector<char>>& board) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    dfs(i, j - 1, board, 'L');
                    dfs(i, j + 1, board, 'R');
                    dfs(i - 1, j, board, 'U');
                    dfs(i + 1, j, board, 'D');
                }
            }
        }
        return sum;
    }
};