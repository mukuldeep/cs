package offl.contest;

public class leet_MaximumScoreofaSplit {

    public static long maximumScore(int[] nums) {
        int[] sufMin = new int[nums.length];
        sufMin[nums.length-1] = nums[nums.length-1];
        for(int i = nums.length-2; i>=0; i--){
            sufMin[i] = Math.min(sufMin[i+1],nums[i]);
        }

        long mxScore = nums[0] - sufMin[1];
        long pfSum = nums[0];

        for(int i=1; i<nums.length-1;i++){
            pfSum += nums[i];
            mxScore = Math.max(mxScore, pfSum - sufMin[i+1]);
        }

        return mxScore;

    }


        public static void main(String[] args){
            int[] nums = {2, 7, 11, 15};
            System.out.println(maximumScore(nums));
        }
}
