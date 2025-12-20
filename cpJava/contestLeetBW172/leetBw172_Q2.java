package offl.contestLeetBW172;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class leetBw172_Q2 {

    public static int[] fn(int[] nums, int target){
        return nums;
    }


    public static int maxSumDivisibleByThree(int[] nums) {
        ArrayList<Integer> r0 = new ArrayList<>();
        ArrayList<Integer> r1 = new ArrayList<>();
        ArrayList<Integer> r2 = new ArrayList<>();
        for (int x : nums) {
            if (x % 3 == 0) r0.add(x);
            else if (x % 3 == 1) r1.add(x);
            else r2.add(x);
        }
        r0.sort(Collections.reverseOrder());
        r1.sort(Collections.reverseOrder());
        r2.sort(Collections.reverseOrder());

        int ans = 0;

        //(0,0,0)
        if(r0.size()>2){
            ans =Math.max(ans, r0.get(0)+r0.get(1)+r0.get(2));
        }

        //(1,1,1)
        if(r1.size()>2){
            ans=Math.max(ans, r1.get(0)+r1.get(1)+r1.get(2));
        }

        //(2,2,2)
        if(r2.size()>2){
            ans= Math.max(ans, r2.get(0)+r2.get(1)+r2.get(2));
        }

        //(0,1,2)
        if(!r0.isEmpty() && !r1.isEmpty() && !r2.isEmpty()){
            ans=Math.max(ans, r0.get(0)+r1.get(0)+r2.get(0));
        }

        return ans;
    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] ans = fn(nums, target);

        //System.out.println("Output: " + ans);
        System.out.println("Output: " + Arrays.toString(ans));

        System.out.println();
    }
}
