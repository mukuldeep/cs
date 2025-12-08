package offl.contest;


import java.util.Arrays;

public class leet_KnightDialer {




    public static int knightDialer(int n) {
        int MOD = 1_000_000_007;
        int res = 0;

        int[][] knightMoves = {
                {4,6},//0
                {6,8},
                {7,9},
                {4,8},//3
                {3,9,0},
                {},//5
                {1,7,0},
                {2,6},//7
                {1,3},
                {2,4}//9
//                {5,9},//* 10
//                {5,7}//# 11
        };

        int[][] dp = new int[2][10];
        for(int i=0;i<10;i++) {
            dp[0][i] = 1;
        }

        for(int i=1;i<n;i++){
            int x = (i&1)==1?1:0;
            int _x = (i&1)==1?0:1;
            for(int j=0;j<10;j++) {
                dp[x][j] = 0;
                for (int k : knightMoves[j]){
                    dp[x][j] = (dp[x][j]  + dp[_x][k])%MOD;
                }
            }
        }

        for(int i=0;i<10;i++) {
            res = (res + dp[(n&1)==1?0:1][i])%MOD;
        }

        return res;

    }

        public static void main(String[] args){

            int[] ans = {0};
            System.out.println("Output: " + Arrays.toString(ans));

            for(int i=1;i<20;i++){
                System.out.println(i+" = "+knightDialer(i));
            }

            System.out.println();
        }
}
