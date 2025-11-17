package offl.leetcodes;

public class leet_CountPartitionswithEvenSumDifference {
    public int countPartitions(int[] nums) {
        int sum = 0;
        for(int num: nums){
            sum+=num;
        }
        return (((sum&1)==1)? 0 : nums.length-1 );
    }
}
