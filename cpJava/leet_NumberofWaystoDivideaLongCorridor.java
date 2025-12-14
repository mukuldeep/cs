package offl.contest;

import java.util.Arrays;

public class leet_NumberofWaystoDivideaLongCorridor {
    public static long MOD = 1_000_000_007l;

    public static int[] fn(int[] nums, int target){

            return nums;
        }

    public int numberOfWays(String corridor) {
        long ans = 1l;
        int state = 0;
        int cnt = 0;

        for(char ch:corridor.toCharArray()){

            switch (state){
                case 0:
                    if(ch == 'S'){
                        state = 1;
                    }
                    break;
                case 1:
                    if(ch == 'S'){
                        state = 2;
                        cnt = 1;
                    }
                    break;
                case 2:
                    if(ch == 'S'){
                        state = 1;
                        cnt = 0;
                    }else{//P
                        state = 3;
                        cnt++;
                    }
                    break;
                case 3:
                    if(ch == 'S'){
                        ans *= cnt;
                        ans %= MOD;
                        state = 1;
                        cnt = 0;
                    }else{//P
                        cnt++;
                    }
                    break;
            }
        }

        if(state == 1){
            return 0;
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
