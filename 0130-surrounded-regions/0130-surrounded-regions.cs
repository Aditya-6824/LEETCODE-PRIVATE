public class Solution {
    public void Solve(char[][] board) {
        if (board.Length == 0 || board[0].Length == 0) return;
        int n = board.Length;
        int m = board[0].Length;

        // Protect safe cells.
        // Horizontal edges.
        for (int i = 0; i < n; i++) {
            ProtectFlood(board, i, 0, n, m);
            ProtectFlood(board, i, m-1, n, m);
        }
        // Vertical edges.
        for (int j = 0; j < m; j++) {
            ProtectFlood(board, 0, j, n, m);
            ProtectFlood(board, n-1, j, n, m);
        }

        // Iterate over all cells to flip them to their final state.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Flip(board, i, j);
            }
        }
    }

    public void ProtectFlood(char[][] board, int i, int j, int n, int m) {
        // Bounds check, as well as check it's an O cell.
        if (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 'O') {
            // Flip "safe" cells to "S".
            board[i][j] = 'S'; // "Safe"? "Sentinel"?
            ProtectFlood(board, i+1, j, n, m);
            ProtectFlood(board, i-1, j, n, m);
            ProtectFlood(board, i, j+1, n, m);
            ProtectFlood(board, i, j-1, n, m);
        }
    }

    public void Flip(char[][] board, int i, int j) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        else if (board[i][j] == 'S') board[i][j] = 'O';
    }
}