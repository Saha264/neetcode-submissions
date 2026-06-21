class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // 1. We must try to start the word from EVERY possible cell on the board
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If the starting cell matches the first letter, kick off backtracking
                if ( backtrack(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(int row, int col, int index, vector<vector<char>>& board, const string& word) {
        // Base Case: We successfully matched every letter in the word
        if (index == word.size()) {
            return true;
        }

        // Boundary Check: Ensure we are inside the grid
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }

        // Character Check: Does the current cell match the character we need?
        if (board[row][col] != word[index]) {
            return false;
        }

        // Step 1: Mark the current cell as visited to prevent reusing it
        char temp = board[row][col];
        board[row][col] = '#'; 

        // Step 2: Explore all 4 directions (Up, Down, Left, Right)
        // If ANY direction returns true, we found the word!
        bool found = backtrack(row - 1, col, index + 1, board, word) || // Up
                     backtrack(row + 1, col, index + 1, board, word) || // Down
                     backtrack(row, col - 1, index + 1, board, word) || // Left
                     backtrack(row, col + 1, index + 1, board, word);   // Right

        // Step 3: BACKTRACK - Restore the cell's original character for other paths
        board[row][col] = temp;

        return found;
    }
};