class Solution {
private:
    int const ALIVE_MASK = 1;
    int const NEXT_GEN_ALIVE_MASK = 2;

    int getNeighborCount(int x, int y, vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        int iStart = max(0, x - 1), iEnd = min(x + 1, n - 1);
        int jStart = max(0, y - 1), jEnd = min(y + 1, m - 1);
        int neighborCount = -board[x][y];
        for (int i = iStart; i <= iEnd; i++) {
            for (int j = jStart; j <= jEnd; j++) {
                neighborCount += (board[i][j] & ALIVE_MASK);
            }
        }
        return neighborCount;
    }

    int getNextStatus(bool isAlive, int neighborCount) {
        if (neighborCount == 3) return NEXT_GEN_ALIVE_MASK;
        if (isAlive && neighborCount == 2) return NEXT_GEN_ALIVE_MASK;
        return 0;
    }

    void updateBoardToNextStatus(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighborCount = getNeighborCount(i, j, board);
                board[i][j] |= getNextStatus(board[i][j] & ALIVE_MASK, neighborCount);
            }
        }
    }

    int normalizeCell(int nextGenValue) {
        if (nextGenValue & NEXT_GEN_ALIVE_MASK) return ALIVE_MASK;
        return 0;
    }

    void normalizeBoard(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = normalizeCell(board[i][j]);
            }
        }
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        updateBoardToNextStatus(board);
        normalizeBoard(board);
    }
};
