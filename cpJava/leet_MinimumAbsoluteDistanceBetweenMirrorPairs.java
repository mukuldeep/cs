package offl.contest;

import java.util.HashMap;

public class leet_MinimumAbsoluteDistanceBetweenMirrorPairs {

    int reverse(int n) {
        int rev = 0;
        while (n != 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    public int minMirrorPairDistance(int[] nums) {
        HashMap<Integer,Integer> revPos = new HashMap<>();
        int ans = nums.length+1;
        for(int i=0;i<nums.length;i++){
            if(revPos.containsKey(nums[i])){
                ans = Math.min(ans,Math.abs(i-revPos.get(nums[i])));
            }

            int rev = reverse(nums[i]);
            revPos.put(rev,i);
        }

        return ans==(nums.length+1)?-1:ans;

    }
}
