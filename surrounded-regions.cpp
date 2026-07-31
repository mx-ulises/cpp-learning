struct Pair {
    int x;
    int y;
};

class Solution {
private:
    bool validPosition(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || board.size() == i) return false;
        if (j < 0 || board[i].size() == j) return false;
        return true;
    }

    bool isSurrounded(vector<vector<char>>& board, int i, int j) {
        if (!validPosition(board, i, j)) {
            return false;
        }
        if (board[i][j] == 'X' || board[i][j] == '?') {
            return true;
        }
        board[i][j] = '?';
        bool surrounded = isSurrounded(board, i - 1, j);
        surrounded &= isSurrounded(board, i + 1, j);
        surrounded &= isSurrounded(board, i, j - 1);
        surrounded &= isSurrounded(board, i, j + 1);
        return surrounded;
    }

    void replaceSurroundedArea(vector<vector<char>>& board, int i, int j, char c) {
        if (!validPosition(board, i, j) || board[i][j] != '?') {
            return;
        }
        board[i][j] = c;
        replaceSurroundedArea(board, i + 1, j, c);
        replaceSurroundedArea(board, i - 1, j, c);
        replaceSurroundedArea(board, i, j + 1, c);
        replaceSurroundedArea(board, i, j - 1, c);
    }

public:
    void solve(vector<vector<char>>& board) {
        vector<Pair> positionsToClean;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O' && isSurrounded(board, i, j)) {
                    replaceSurroundedArea(board, i, j, 'X');
                } else {
                    positionsToClean.push_back({i, j});
                }
            }
        }
        for (auto position : positionsToClean) {
            replaceSurroundedArea(board, position.x, position.y, 'O');
        }
    }
};
