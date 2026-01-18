class Solution {
    public int largestMagicSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        int[][] rowPref = new int[m][n];
        int[][] colPref = new int[m][n];
        int[][] diag1 = new int[m][n]; // tl to br
        int[][] diag2 = new int[m][n]; // tr to bl

        // prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPref[i][j] = grid[i][j] + (j > 0 ? rowPref[i][j - 1] : 0);
                colPref[i][j] = grid[i][j] + (i > 0 ? colPref[i - 1][j] : 0);
                diag1[i][j] = grid[i][j] +
                        (i > 0 && j > 0 ? diag1[i - 1][j - 1] : 0);
                diag2[i][j] = grid[i][j] +
                        (i > 0 && j + 1 < n ? diag2[i - 1][j + 1] : 0);
            }
        }

        int maxK = Math.min(m, n);

        // larger squares first
        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagic(grid, rowPref, colPref, diag1, diag2, i, j, k))
                        return k;
                }
            }
        }

        return 1;
        
    }

    private boolean isMagic(
            int[][] grid,
            int[][] rowPref,
            int[][] colPref,
            int[][] diag1,
            int[][] diag2,
            int r,
            int c,
            int k
    ) {
        int endR = r + k - 1;
        int endC = c + k - 1;

        // target sum = first row
        int target = rowPref[r][endC] - (c > 0 ? rowPref[r][c - 1] : 0);

        // check rows
        for (int i = r; i <= endR; i++) {
            int sum = rowPref[i][endC] - (c > 0 ? rowPref[i][c - 1] : 0);
            if (sum != target) return false;
        }

        // check columns
        for (int j = c; j <= endC; j++) {
            int sum = colPref[endR][j] - (r > 0 ? colPref[r - 1][j] : 0);
            if (sum != target) return false;
        }

        // main diagonal
        int d1 = diag1[endR][endC] -
                (r > 0 && c > 0 ? diag1[r - 1][c - 1] : 0);
        if (d1 != target) return false;

        // anti-diagonal
        int d2 = diag2[endR][c] -
                (r > 0 && endC + 1 < grid[0].length ? diag2[r - 1][endC + 1] : 0);
        if (d2 != target) return false;

        return true;
    }
}