package offl.contest;

import java.util.Arrays;

public class leet_CounttheNumberofComputerUnlockingPermutations {
    public static int[] fn(int[] nums, int target){

            return nums;
        }

        static int MOD = 1_000_000_007;
    public int countPermutations(int[] complexity) {

        int cnt = 0;
        for(int cmp: complexity){
            if(cmp == complexity[0]){
                cnt++;
            }else if(cmp < complexity[0]){
                return 0;
            }
        }

        if(cnt > 1){
            return 0;
        }

        long ans = 1l;
        for(int i=2;i<complexity.length;i++){
            ans*=i;
            ans%=MOD;
        }

        return (int)ans;
    }


        public static void main(String[] args){
            long num1 = 42;

            int[] nums = {2, 7, 11, 15};
            int target = 9;

            int[] ans = fn(nums, target);
            System.out.println("Output: " + Arrays.toString(ans));

            System.out.println();
        }
}
