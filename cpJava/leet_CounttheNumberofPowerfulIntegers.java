package offl.contest;

import java.util.Arrays;

public class leet_CounttheNumberofPowerfulIntegers {

    static long[][] dp = new long[18][2]; // idx, tight
    public static void resetDp(){
        for (int i = 0; i < dp.length; i++) {
            //for (int j = 0; j < dp[0].length; j++) {
                Arrays.fill(dp[i], -1);
            //}
        }
    }

    public static long solve(String num, int digitLimit, int idx, int tight,String suff){//}, String ansSoFar){

        //base condition condition
        if(idx == num.length()){
            //System.out.println(ansSoFar);
            return 1;
        }

        //already in dp state
        if(dp[idx][tight] != -1){
            //System.out.println(ansSoFar+" cnt="+dp[idx][tight]);
            return dp[idx][tight];
        }
        //to run upto
        int limit = (tight==1)?(num.charAt(idx)-'0') : 9;
        limit = Math.min(limit,digitLimit);

        char ch = ' ';
        if((num.length()-idx) <= suff.length()){
            int ind = suff.length() - (num.length()-idx);
            ch = suff.charAt(ind);
        }

        long ans = 0;
        for(int i=0;i<=limit; i++){
            //int updateCnt = i==1?cnt+1:cnt;
            if((ch==' ') || ((ch-'0')==i)) {
                int d = (num.charAt(idx) - '0');
                ans += solve(num, digitLimit, idx + 1, (((tight == 1) & (i == d) )? 1 : 0), suff);//, ansSoFar + i);
            }
        }
        return dp[idx][tight] = ans;
    }

    public static long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        String rights = String.valueOf(finish);
        String lefts = String.valueOf(start-1);
        while(lefts.length()<rights.length()){
            lefts= "0"+lefts;
        }

        resetDp();
        long left = solve(lefts,limit,0,1,s);//,"");
        resetDp();
        long right = solve(String.valueOf(finish),limit,0,1,s);//,"");

        System.out.println("left="+left);
        System.out.println("right="+right);

        long ans = right-left;
        return ans>0?ans:0;
    }

    public static void main(String[] args) {

//        long start = 1;
//        long finish = 6000;
//        int limit = 4;
//        String s = "124";

//        long start = 15;
//        long finish = 215;
//        int limit = 6;
//        String s = "10";

//        long start = 100, finish = 9000;
//        int limit = 3;
//        String s = "1000";

        long start = 697662853, finish = 11109609599885L;
        int limit = 6;
        String s = "5";





        System.out.println(numberOfPowerfulInt(start,finish,limit,s));


    }

}
