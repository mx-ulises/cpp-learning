class Solution {
private:
    bool isBattleship(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0) return false;
        return board[x][y] == 'X'; 
    }

    bool isNewShip(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == '.') {
            return false;
        }
        if (isBattleship(board, x - 1, y) || isBattleship(board, x, y - 1)) {
            return false;
        }
        return true;
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int ships = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (isNewShip(board, i, j)) {
                    ships++;
                }
            }
        }
        return ships;
    }
};
