class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1_000_000;
        for(int i=k-1; i < nums.length; i++){
            ans = Math.min(ans, nums[i]-nums[i-k+1]);
        }
        return ans;
    }
}