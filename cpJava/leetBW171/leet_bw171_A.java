package offl.contestLeetBW171;


import java.util.Arrays;


public class leet_bw171_A {
    public static int[] fn(int[] nums, int target){

        return nums;
    }

    private static boolean isPrime(long n) {
        if(n<2) return false;
        if(n%2 == 0) return n == 2;
        for(long i=3; i*i<=n; i+=2) {
            if(n%i==0) return false;
        }
        return true;
    }

    public static boolean completePrime(int num) {
        String s=Integer.toString(num);
        int n =s.length();
        for(int i = 1; i <= n; i++) {
            long pf = Long.parseLong(s.substring(0, i));
            if(!isPrime(pf)) return false;
        }
        for(int i = 0; i < n; i++) {
            long sf =Long.parseLong(s.substring(i));
            if(!isPrime(sf)) return false;
        }
        return true;


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
