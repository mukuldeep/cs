package offl.leetcodes;

public class leet_MaximumAbsoluteSumofAnySubarray {

    public int maxAbsoluteSum(int[] nums) {

        int mx = 0;
        int predpMx = 0;
        int predpMn = 0;
        int dpMx;
        int dpMn;

        for(int i=0; i<nums.length; i++){
            dpMx = Math.max(0, Math.max(predpMx+nums[i], nums[i]));
            dpMn = Math.min(0, Math.min(predpMn+nums[i], nums[i]));
            mx = Math.max(mx, Math.max(Math.abs(dpMx), Math.abs(dpMn)));

            predpMx = dpMx;
            predpMn = dpMn;
        }

        return mx;
    }
}
