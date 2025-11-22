package offl.leetcodes;

import java.util.Arrays;

public class leet_DigitDP_NumberofDigitOne {

    static long[][][] dp = new long[12][2][12]; // idx, tight, cnt

    public static void resetDp(){
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
    }

    public static long solve(String num, int idx, int tight, int cnt){

        //base condition condition
        if(idx == num.length()){
            return cnt;
        }

        //already in dp state
        if(dp[idx][tight][cnt] != -1){
            return dp[idx][tight][cnt];
        }
        //to run upto
        int limit = (tight==1)?(num.charAt(idx)-'0') : 9;
        int ans = 0;
        for(int i=0;i<=limit; i++){
            int updateCnt = i==1?cnt+1:cnt;
            ans+= solve(num, idx+1,(((tight==1)&(i==(num.charAt(idx)-'0'))?1:0)),updateCnt);
        }
        return dp[idx][tight][cnt] = ans;
    }

    public static int countDigitOne(int n) {
        resetDp();
        return (int)solve(String.valueOf(n),0,1,0);
    }

    public static void main(String[] args){

        long num1 = 13, num2 = 4848;
//        System.out.println(wavinessUpTo(num1-1));
//        System.out.println(wavinessUpTo(num2));


        System.out.println(countDigitOne((int)num1));



//        int[] nums = new int[]{2,3,4,5};
//        int[][] nums2d = new int[][]{{2,3}, {4,6}};

//        int ans = 0;//longestDupSubstring(str);
//        System.out.println("ans=" + ans);

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
