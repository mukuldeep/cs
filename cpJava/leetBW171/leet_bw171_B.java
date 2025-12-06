package offl.contestLeetBW171;


import java.util.Arrays;


public class leet_bw171_B {

    static boolean[] isPalin = new boolean[6005];
    static int[] nextPalin = new int[6005];
    static int[] prePalin = new int[6005];

    private static boolean isBinaryPalindrome(int x) {
        String s=Integer.toBinaryString(x);
        int l=0, r=s.length()-1;
        while(l<r){
            if(s.charAt(l++) != s.charAt(r--))
                return false;
        }
        return true;
    }

    private static void preProcess(){
        Arrays.fill(isPalin, false);
        for(int i=0;i<6005;i++){
            if(isBinaryPalindrome(i)){
                isPalin[i] = true;
            }
        }

        int pre = 0;
        for(int i=0;i<6005;i++){
            if(isPalin[i]){
                pre = i;
            }
            prePalin[i] = pre;
        }

        int post = -1;
        for(int i=6004;i>=0;i--){
            if(isPalin[i]){
                post = i;
            }
            nextPalin[i] = post;
        }
    }




    public static int[] minOperations(int[] nums) {
        preProcess();

        int[] ans = new int[nums.length];
        for(int i=0;i< nums.length; i++){
            ans[i] = Math.min(Math.abs(nums[i]-prePalin[nums[i]]),Math.abs(nums[i]-nextPalin[nums[i]]));
        }
        return ans;

    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] ans =  minOperations(nums); //fn(nums, target);
        System.out.println("Output: " + Arrays.toString(ans));

        System.out.println();
    }
}
