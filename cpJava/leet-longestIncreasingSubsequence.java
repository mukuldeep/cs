package offl.leetcodes;

import java.util.List;

public class longestIncreasingSubsequence {



    public static int lengthOfLIS(int[] nums) {

        int[] dp = new int[nums.length];
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i< nums.length; i++){
            dp[i] = 1;
            for(int j=0; j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }
            ans = Math.max(ans, dp[i]);
        }

        return ans;
    }


    public static void main(String[] args){
        int[] nums = {1, 2, 3, 4, 7, 2, 6, 10, 13, 7, 23, 8};
        //ArrayList<Integer> list = new ArrayList<>();

        int ans = lengthOfLIS(nums);

        System.out.println(ans);
//        for (Integer el:ans) {
//            System.out.print(el+", ");
//        }
//        System.out.println();





    }
}
