#include <vector>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int liveNeighbors = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        
                        if (board[ni][nj] == 1 || board[ni][nj] == 2) {
                            liveNeighbors++;
                        }
                    }
                }
                
                if (board[i][j] == 1) { 
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 2; 
                    }
                } else { 
                    if (liveNeighbors == 3) {
                        board[i][j] = 3; 
                    }
                }
            }
        }

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0; 
                } else if (board[i][j] == 3) {
                    board[i][j] = 1; 
                }
            }
        }
    }
};