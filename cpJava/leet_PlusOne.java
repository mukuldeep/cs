package offl.contest;

import java.util.Arrays;

public class leet_PlusOne {

    public static int[] plusOne(int[] digits) {

        int carry = 1;
        for(int i=digits.length-1;i>=0; i--){
            digits[i]+=carry;

            if(digits[i] == 10){
                digits[i] = 0;
                carry = 1;
            }else{
                carry = 0;
            }
        }

        if(carry == 1){
            int[] ans = new int[digits.length+1];
            ans[0] = 1;
            for(int i=0;i<digits.length;i++){
                ans[i+1] = digits[i];
            }
            return ans;
        }
        return digits;
    }

    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {5};

        for(int i=0;i<1000;i++) {
            nums = plusOne(nums);
            System.out.println("Output: " + Arrays.toString(nums));
        }



        System.out.println();
    }


}
