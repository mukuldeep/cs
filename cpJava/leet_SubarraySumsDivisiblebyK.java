package offl.contest;

public class leet_SubarraySumsDivisiblebyK {

    public static int subarraysDivByK(int[] nums, int k) {
        int[] dp = new int[k];
        int prefSum = 0;
        int ans = 0;
        dp[prefSum] = 1;
        for(int i=0; i< nums.length;i++){
            prefSum = (((prefSum+nums[i])%k)+k)%k;
            ans += dp[prefSum];
            dp[prefSum]++;
        }
        return ans;
    }


    public static void main(String[] args) {

        int[] nums = new int[]{4,5,0,-2,-3,1};
        int k = 5;

//        int[] nums = new int[]{5};
//        int k = 9;

        long ans = subarraysDivByK(nums,k);
        System.out.println(ans);


    }
}
