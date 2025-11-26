package offl.contest;

public class leet_PathsinMatrixWhoseSumIsDivisiblebyK {

    static int MOD = 1_000_000_007;

    public static int numberOfPaths(int[][] grid, int k) {
        int[][][] dp = new int[grid.length][grid[0].length][k+1];
        int sm = 0;
        for(int i=0;i<grid.length;i++){
            sm+=grid[i][0];
            dp[i][0][sm%k]=1;
        }
        sm=0;
        for(int i=0;i<grid[0].length;i++){
            sm+=grid[0][i];
            dp[0][i][sm%k]=1;
        }

        for(int i=1; i<grid.length; i++){
            for(int j=1; j<grid[0].length;j++){
                for(int kk = 0; kk<k;kk++){
                    dp[i][j][(kk+grid[i][j])%k] = (dp[i-1][j][kk]+ dp[i][j-1][kk])%MOD;
                }
            }
        }

        return dp[grid.length-1][grid[0].length-1][0];

    }

    public static void main(String[] args) {

//        int[][] grid = {{5,2,4},{3,0,5},{0,7,2}};
//        int k = 3;

//        int[][] grid = {{0,0}};
//        int k = 5;

        int[][] grid = {{7,3,4,9},{2,3,6,2},{2,3,7,0}};
        int k = 1;

        System.out.println(numberOfPaths(grid,k));
    }

}
