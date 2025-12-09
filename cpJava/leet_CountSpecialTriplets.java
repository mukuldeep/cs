package offl.contest;

import java.util.Arrays;
import java.util.HashMap;

public class leet_CountSpecialTriplets {
    static int MOD = 1_000_000_007;

    public int specialTriplets(int[] nums) {
        int[] allArr = new int[1_000_07];
        int[] preArr = new int[1_000_07];

        for(int x:nums){
            allArr[x]++;
        }

        int ans = 0;

        for(int x:nums){
            allArr[x]--;
            if( (x<<1)<100_007 && allArr[(x<<1)]>0 && preArr[(x<<1)]>0){
                long total = ((long) allArr[(x<<1)] * preArr[(x<<1)])%MOD;
                ans += total;
                ans %= MOD;
            }

            preArr[x]++;
        }

        return ans;
    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] ans = {0};
        System.out.println("Output: " + Arrays.toString(ans));

        System.out.println();
    }

}
