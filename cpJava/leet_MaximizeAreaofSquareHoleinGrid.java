class Solution {

    public static int longestConsecutive(int[] nums) {
        Arrays.sort(nums);
        int maxLen = 1;
        int currLen = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                currLen++;
            } else {
                currLen = 1;
            }
            maxLen = Math.max(maxLen, currLen);
        }
        return maxLen;
    }

    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {

        int lxn = Math.min(
            longestConsecutive(hBars),
            longestConsecutive(vBars)
        )+1;
        return lxn*lxn;    
    }
}