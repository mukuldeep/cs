package offl.contest;

import java.util.Arrays;

public class leet_Best_Time_to_Buy_and_Sell_Stock_V {

    static long[][][] dp; //[index] [k] [state 0=notHolding 1=bought 2=sold]
    static int[] prices;
    static int K;

    public static long maxProfit(int ind, int k, int state){
        if(ind >= prices.length){
            return state==0?0:Long.MIN_VALUE/3;
        }

        if(dp[ind][k][state] != -1){
            return dp[ind][k][state];
        }

        long ans = maxProfit(ind+1,k,state); // not including this element

        switch (state){
            case 0: // not holding any transaction
                ans = Math.max(ans,maxProfit(ind+1,k,1)-prices[ind]);//buy / start transaction
                ans = Math.max(ans,maxProfit(ind+1,k,2)+prices[ind]);//sell / start transaction
                break;
            case 1://already bought
                if(k<K) {
                    ans = Math.max(ans, maxProfit(ind + 1, k + 1, 0) + prices[ind]);//sell / end transaction
                }
                break;
            case 2:
                if(k<K) {
                    ans = Math.max(ans, maxProfit(ind + 1, k + 1, 0) - prices[ind]);//buy / end transaction
                }
                break;
        }


        return dp[ind][k][state] = ans;

    }

    public static long maximumProfit(int[] pricesx, int k) {
        prices = pricesx;
        K = k;
        dp = new long[prices.length+1][k+1][3];
        for(long[][] dpx: dp){
            for(long[] dpxx : dpx){
                Arrays.fill(dpxx,-1);
            }
        }

        return maxProfit(0,0,0);
    }


    public static void main(String[] args){

        int[] nums = {1,7,9,8,2};
        int target = 2;

        long ans = maximumProfit(nums, target);
        System.out.println("Output: " + ans);


        System.out.println();
    }
}
