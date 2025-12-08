package offl.contest;

import java.util.Arrays;

public class leet_MinimumFallingPathSum {


    public static int minFallingPathSum(int[][] matrix) {

        int[][] dp = new int[matrix.length][matrix[0].length];

        dp[0] = matrix[0];
        for(int row = 1; row < dp.length; row++){
            for(int col = 0;col<dp[0].length;col++){
                dp[row][col] = dp[row-1][col];
                if(col>0) {
                    dp[row][col] = Math.min(dp[row][col], dp[row-1][col - 1]);
                }
                if(col < dp[0].length-1) {
                    dp[row][col] = Math.min(dp[row][col], dp[row-1][col + 1]);
                }
                dp[row][col]+=matrix[row][col];
            }
        }

        for(int i=0;i<dp.length;i++) {
            System.out.println(Arrays.toString(dp[0]));
        }

        int ans = dp[dp.length-1][0];
        for(int col = 1;col<dp[0].length;col++) {
            ans = Math.min(ans,dp[dp.length-1][col]);
        }

        return ans;
    }


        public static void main(String[] args){

            int[][] grid = {{2,1,3},{6,5,4},{7,8,9}};

            minFallingPathSum(grid);
            int[] ans = {0};
            System.out.println("Output: " + Arrays.toString(ans));

            System.out.println();
        }
}
