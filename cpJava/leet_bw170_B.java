package offl.contest;

public class leet_bw170_B {


    public static int waviness(int n) {
        if (n < 100) return 0;

        int[] digits = new int[10];
        int len = 0;

        while (n > 0) {
            digits[len++] = (int)(n % 10);
            n /= 10;
        }
        int count = 0;

        for (int i = 1; i < len - 1; i++) {
            int prev = digits[i - 1];
            int curr = digits[i];
            int next = digits[i + 1];

            if (curr > prev && curr > next) count++;      // peaks
            else if (curr < prev && curr < next) count++; // valleys
        }

        return count;
    }


    public static int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i= num1; i<=num2; i++){
            ans += waviness(i);
        }
        return ans;
    }

    public static void main(String[] args){

//        int[] nums = new int[]{2,3,4,5};
//        int[][] nums2d = new int[][]{{2,3}, {4,6}};

        int m=1,n=100000;
        int ans = totalWaviness(m,n);
        System.out.println("ans=" + ans);

//        int[] ans = {};//longestDupSubstring(str);
//        for(int nm: ans) {
//            System.out.println(" " + nm);
//        }System.out.println();

//
//        String[] strs = {"banana"};
//        for(String str: strs) {
//            String ans = "";//longestDupSubstring(str);
//            System.out.println("ans=" + ans);
//        }

    }
}
