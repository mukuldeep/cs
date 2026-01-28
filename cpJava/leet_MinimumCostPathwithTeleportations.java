package offl.contest;

import java.util.*;

public class leet_MinimumCostPathwithTeleportations {

    public static long minCost(int[][] grid, int k){
        int m=grid.length;
        int n=grid[0].length;
        long INF=Long.MAX_VALUE / 4;

        long[][] dp=new long[m][n];
        for(int i=0;i<m;i++){
            Arrays.fill(dp[i], INF);
        }

        //0 teleports
        dp[0][0]=0;//grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0)dp[i][j]=Math.min(dp[i][j], dp[i-1][j]+grid[i][j]);
                if(j>0)dp[i][j]=Math.min(dp[i][j], dp[i][j-1]+grid[i][j]);
            }
        }

        long ans=dp[m-1][n-1];

        //[value, row, col]
        List<int[]> cellsByVal=new ArrayList<>();
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                cellsByVal.add(new int[]{grid[r][c], r, c});
            }
        }

        cellsByVal.sort((a, b) -> Integer.compare(b[0], a[0]));

        //k teleports
        for(int t=0;t<k;t++){
            long[][] newDp=new long[m][n];
            for(int i=0;i<m;i++){
                Arrays.fill(newDp[i], INF);
            }

            Map<Integer, Long> bestCostForVal=new HashMap<>();
            long currentMin=INF;

            for(int[] cell : cellsByVal){
                int val=cell[0];
                int r=cell[1];
                int c=cell[2];

                currentMin=Math.min(currentMin, dp[r][c]);
                bestCostForVal.put(val, currentMin);
            }

            // Update DP for this teleport level
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){

                    //teleport directly
                    newDp[i][j]=bestCostForVal.get(grid[i][j]);

                    //normal moves
                    if(i>0)newDp[i][j]=Math.min(newDp[i][j], newDp[i-1][j]+grid[i][j]);
                    if(j>0)newDp[i][j]=Math.min(newDp[i][j], newDp[i][j-1]+grid[i][j]);

                    //don't teleport
                    newDp[i][j]=Math.min(newDp[i][j], dp[i][j]);
                }
            }

            dp=newDp;
            ans=Math.min(ans, dp[m-1][n-1]);
        }

        return (int)ans;
    }


        public static void main(String[] args){

            int[][] grid={
                    {1,3,3},
                    {2,5,4},
                    {4,3,5}};
            int k=2;

            System.out.println("Output: "+minCost(grid,k));

            System.out.println();
        }
}
