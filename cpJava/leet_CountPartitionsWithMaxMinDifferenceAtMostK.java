package offl.contest;
import java.util.PriorityQueue;
public class leet_CountPartitionsWithMaxMinDifferenceAtMostK {

    static int MOD = 1_000_000_007;

    public static int countPartitions(int[] nums, int k) {

        PriorityQueue<int[]> mnPq = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        PriorityQueue<int[]> mxPq = new PriorityQueue<>((a, b) -> (b[0] - a[0]));

        int[] prefSumDp = new int[nums.length+5];
        int[] dp = new int[nums.length+5];

        prefSumDp[0]=1;
        dp[0] = 1;

        int fp = 0;
        for(int i=0; i<nums.length; i++){

            mnPq.add(new int[]{nums[i],i});
            mxPq.add(new int[]{nums[i],i});

            while( !(mxPq.isEmpty() || mnPq.isEmpty()) && ((mxPq.peek()[0] - mnPq.peek()[0])>k)){
                fp++;
                while ( (!mxPq.isEmpty()) && mxPq.peek()[1]<fp){
                    mxPq.remove();
                }
                while ( (!mnPq.isEmpty()) && mnPq.peek()[1]<fp){
                    mnPq.remove();
                }
            }

            System.out.println(" fp = "+fp);
//            for(int j=fp;j<=i;j++){
//                dp[i+1] += dp[j];
//            }

            dp[i+1] = ( prefSumDp[i] - ((fp-1 >= 0)?prefSumDp[fp-1]:0) + MOD) % MOD;
            prefSumDp[i+1] = (prefSumDp[i]+dp[i+1]) % MOD;

            for(int x: dp){
                System.out.print(x+" ");
            }System.out.println();

        }

        //return prefSumDp[nums.length];
        return dp[nums.length];
    }

    public static void main(String[] args){

//        int[] nums = new int[]{9,4,1,3,7};
//        int k = 4;

        int[] nums = new int[]{3,3,4};
        int k = 0;


        System.out.println(countPartitions(nums,k));
    }
}
