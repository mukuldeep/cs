package offl.leetcodes;

public class leet_SumofVariableLengthSubarrays {
    public int subarraySum(int[] nums) {

        int[] prefixSum = new int[nums.length];
        prefixSum[0] = nums[0];
        int ans=nums[0];
        int start = 0;
        for(int i=1; i<nums.length; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            start = Math.max(0,i-nums[i]);
            ans += prefixSum[i];
            if(start>0){
                ans-=prefixSum[start-1];
            }
        }

        return ans;

    }
}
