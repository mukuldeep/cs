package offl.contest;

import java.util.Arrays;

public class leet_DigitDp_TotalWavinessofNumbersinRangeII {

    static long[][][][][][] dp = new long[17][2][12][12][17][4]; //idx, tight, prevPrev, prev, cnt, alteast3

    public static void resetDp(){
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                for (int k = 0; k < dp[0][0].length; k++) {
                    for (int l = 0; l < dp[0][0][0].length; l++) {
                        for (int m = 0; m < dp[0][0][0][0].length; m++) {
                            Arrays.fill(dp[i][j][k][l][m], -1);
                        }
                    }
                }
            }
        }
    }

    public static long solve(String num, int idx, int tight, int prevPrev, int prev,  int cnt, int alteast3) {


        //base case
        if(idx == num.length()) {
            return cnt;
        }

        System.out.println("checking:"+prevPrev+""+prev+""+num.charAt(idx) + " alteast3:"+alteast3);

        //dp hit
        if(dp[idx][tight][prevPrev][prev][cnt][alteast3] != -1) {
            System.out.println("dp hit");
            return dp[idx][tight][prevPrev][prev][cnt][alteast3];
        }

        //
        int limit = (tight==1)?(num.charAt(idx)-'0') : 9;
        long ans = 0;
        for(int i=0; i<=limit;i++) {

            int updatedCnt = cnt;

            if(alteast3>1) {
                if(((prevPrev > prev) && (prev < i)) || ((prevPrev < prev) && (prev > i))){
                    updatedCnt++;
                }
            }

//            if(((tight==0) && (((prevPrev > prev) && (prev < i)) || ((prevPrev < prev) && (prev > i)))
//            || ((tight==1) && (i<=num.charAt(idx)-'0') && (((prevPrev > prev) && (prev < i)) || ((prevPrev < prev) && (prev > i))))
//            )) {
//                if(alteast3>2) {
//                    System.out.println("p n p "+prevPrev+" "+prev+" "+i);
//                    updatedCnt++;
//                }
//            }

            int updatedTight = ((tight==1) && (i == (num.charAt(idx)-'0')))?1:0;
            int updatedalteast3 = (i==0 && alteast3==0 )?0:((alteast3>=3)?3:alteast3+1);
            ans += solve(num,idx+1,updatedTight,prev, i,updatedCnt,updatedalteast3);
        }

        return dp[idx][tight][prevPrev][prev][cnt][alteast3] = ans;
    }


    public static long totalWaviness(long num1, long num2) {
        resetDp();
        long rNum = solve(String.valueOf(num2),0,1,0,0,0,0);
        System.out.println("right="+rNum);

        resetDp();
        long lNum = solve(String.valueOf(num1-1),0,1,0,0,0,0);
        System.out.println("left="+lNum);

        return rNum - lNum;
    }

    public static void main(String[] args){

        long num1 = 4848, num2 = 4848;//2
//        long num1 = 120, num2 = 130;//3
//        long num1 = 198, num2 = 202;//3
//        System.out.println(wavinessUpTo(num1-1));
//        System.out.println(wavinessUpTo(num2));

        System.out.println(totalWaviness(num1,num2));

    }

    //0120
    //0121
    //0122
    //0123
    //0124
    //0125
    //0126
    //0127
    //0128
    //0129
    //0130




}
