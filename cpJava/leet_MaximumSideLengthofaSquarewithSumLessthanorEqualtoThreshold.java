class Solution {

    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] pre = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        int maxLen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                while (i + maxLen < m && j + maxLen < n) {
                    int k = maxLen + 1;

                    int sum = pre[i + k][j + k]
                            - pre[i][j + k]
                            - pre[i + k][j]
                            + pre[i][j];

                    if (sum <= threshold) {
                        maxLen++;
                    } else {
                        break;
                    }
                }
            }
        }

        return maxLen;
    }


}