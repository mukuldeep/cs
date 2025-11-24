package offl.contest;

public class leet_PizzaWith3nSlices {

    public static int maxNonAdjacentSumInArray(int[] nums){
        int k = nums.length/3;
        int[][] dp = new int[k+1][nums.length+1];

        for(int i=1; i<=nums.length; i++){
            dp[0][i] = Math.max(
                    dp[0][i-1],
                    nums[i-1]
            );
        }

        for(int kk = 1; kk <= k; kk++){
            for(int i=1;i<=nums.length; i++){
                dp[kk][i] = Math.max(
                        (i>1?dp[kk-1][i-2]:0)+nums[i-1],//selecting this
                        dp[kk][i-1]//previously selected
                );
            }
        }

//        int ans = 0;
//        for(int i=1; i<dp[k].length; i++){
//            ans = Math.max(ans,dp[k][i]);
//        }

        return Math.max(dp[k][dp[k].length-1],dp[k][dp[k].length-2]);
    }


    public static int maxSizeSlices(int[] slices) {
        int[] slices1 = new int[slices.length-1];
        for(int i=1;i<slices.length;i++){
            slices1[i-1] = slices[i];
        }
        int last = maxNonAdjacentSumInArray(slices1);

        for(int i=0;i<slices1.length;i++){
            slices1[i] = slices[i];
        }
        int first = maxNonAdjacentSumInArray(slices1);

        return Math.max(last, first);
    }


    public static void main(String[] args){

        //int[] nums = {1,2,3,4,5,6};
        //int[] nums = {8,9,8,6,1,1};
        int numss[][] = {{1,2,3,4,5,6},{8,9,8,6,1,1},{4,1,2,5,8,3,1,9,7}};

        for(int[] nums:numss) {
            System.out.println(maxSizeSlices(nums));
        }



    }
}
