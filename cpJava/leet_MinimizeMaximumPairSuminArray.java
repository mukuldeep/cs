class Solution {
    public int minPairSum(int[] nums) {
        int ans = 0;
        int l = 0, r=nums.length-1;
        Arrays.sort(nums);
        while(l<r){
            ans = Math.max(ans, nums[l++]+nums[r--]);
        }
        return ans;
    }
}