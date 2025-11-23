package offl.contest;

import java.util.Arrays;

public class leet_NumbersWithRepeatedDigits {

    static long[][][][][] dp = new long[12][2][2048][2][2]; // idx, tight, digits bitmask, is repeated, all pref 0

    public static void resetDp(){
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                for (int k = 0; k < dp[0][0].length; k++) {
                    for (int l = 0; l < dp[0][0][0].length; l++) {
                        Arrays.fill(dp[i][j][k][l], -1);
                    }
                }
            }
        }
    }

    public static long solve(String num, int idx, int tight, int bitmask, int isRepeated, int isPref0){
        //base condition
        if(idx == num.length()){
            return isRepeated;
        }

        //repeated subproblem
        if(dp[idx][tight][bitmask][isRepeated][isPref0] != -1){
            return dp[idx][tight][bitmask][isRepeated][isPref0];
        }

        int limit = (tight == 1) ? (num.charAt(idx)-'0'):9;
        int ans = 0;
        for(int i=0;i<= limit; i++){
            int d = num.charAt(idx)-'0';
            int updateIsPref0 = ((isPref0==1) && (i==0))?1:0;

            int updatedBitmask = bitmask | (1<<i);
            int updatedTight = ((tight==1)&&(i == d))? 1: 0;
            int updatedIsRepeated = ((isRepeated==1) || (bitmask == updatedBitmask ))?1:0;

            if(updateIsPref0 == 1){
                updatedBitmask = bitmask;
                updatedIsRepeated = isRepeated;
            }

            ans += solve(num,idx+1,updatedTight, updatedBitmask,updatedIsRepeated,updateIsPref0);
        }

        return dp[idx][tight][bitmask][isRepeated][isPref0] = ans;
    }

    public static int numDupDigitsAtMostN(int n) {
        resetDp();
        return (int)solve(String.valueOf(n),0,1,0,0, 1);

    }


    public static void main(String[] args) {

        long num1 = 10;//262

        System.out.println(numDupDigitsAtMostN((int) num1));

    }
}
