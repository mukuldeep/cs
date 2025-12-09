package offl.contest;

import java.util.Arrays;

public class leet_ClimbingStairsII {

    public static int[] fn(int[] nums, int target){

            return nums;
        }


    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[costs.length+1];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i=0; i<costs.length; i++){
            if(i>=0){
                dp[i+1] = Math.min(dp[i+1],dp[i]+costs[i]+1);
            }
            if(i-1>=0){
                dp[i+1] = Math.min(dp[i+1],dp[i-1]+costs[i]+4);
            }

            if(i-2>=0){
                dp[i+1] = Math.min(dp[i+1],dp[i-2]+costs[i]+9);
            }
        }

        System.out.println(Arrays.toString(dp));

        return dp[n];
    }


        public static void main(String[] args){
            long num1 = 42;

            int[] nums = {2, 7, 11, 15};
            int target = 9;

            int[] ans = fn(nums, target);
            System.out.println("Output: " + Arrays.toString(ans));

            System.out.println();
        }
}
