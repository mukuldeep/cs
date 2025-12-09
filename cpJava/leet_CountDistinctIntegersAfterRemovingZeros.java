package offl.contest;

import java.util.Arrays;

public class leet_CountDistinctIntegersAfterRemovingZeros {
    static long MOD = 1_000_000_007L;

    static long[][] dp = new long[16][2]; // idx, tight, cnt
    public static void resetDp(){
        for (int i = 0; i < dp.length; i++) {
            //for (int j = 0; j < dp[0].length; j++) {
                Arrays.fill(dp[i], -1);
            //}
        }
    }

    public static long solve(String num, int idx, int tight){

        //base condition condition
        if(idx == num.length()){
            return 1;
        }

        //already in dp state
        if(dp[idx][tight] != -1){
            return dp[idx][tight];
        }

        //to run upto
        int limit = (tight==1)?(num.charAt(idx)-'0') : 9;
        int ans = 0;

        for(int i=1; i<=limit; i++){
            int updateTight = ((tight==1)&(i==(num.charAt(idx)-'0'))?1:0);
            ans += solve(num, idx + 1, updateTight);
        }
        return dp[idx][tight] = ans;
    }

    public static long countDistinct(long n) {
        long ans = 0;

        String str = "";
        for(int i=1;i<String.valueOf(n).length();i++){
            str += "9";
            resetDp();
            ans += solve(str, 0, 1);
            //ans %= MOD;
            //System.out.println(str);
        }
        resetDp();
        ans += solve(String.valueOf(n), 0, 1);
        //ans %= MOD;

        return ans;
    }

    public static void main(String[] args){
        long num1 = 10;
        System.out.println(countDistinct((int)num1));
    }
}
