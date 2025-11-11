package offl.leetcodes;

public class leet_OnesAndZeroes {


    public static int findMaxForm(String[] strs, int m, int n) {
        int[] ones = new int[strs.length];
        for(int i=0;i<strs.length; i++){
            for(int j = 0; j< strs[i].length(); j++){
                if(strs[i].charAt(j) == '1'){
                    ones[i]++;
                }
            }
        }


        //dp

        int[][][] dp = new int[2][m+1][n+1];

        for(int i=0; i<strs.length;i++){
            int one_cnt = ones[i];
            int zero_cnt = strs[i].length() - one_cnt;

            for(int mm = 0 ; mm <= m; mm++){
                for(int nn = 0 ; nn <= n; nn++){

                    if(mm-zero_cnt >=0 && nn-one_cnt >= 0) { // can select
                        dp[i%2][mm][nn] = Math.max(dp[(i+1)%2][mm][nn], dp[(i+1)%2][mm-zero_cnt][nn-one_cnt]+1);
                        //dp[i%2][mm+zero_cnt][nn+one_cnt] = Math.max(dp[(i+1)%2][mm+zero_cnt][nn+one_cnt], dp[(i+1)%2][mm][nn]+1);
                    }else{ // can't select
                        dp[i%2][mm][nn] = dp[(i+1)%2][mm][nn];
                    }
                }
            }

            for(int mm = 0 ; mm <= m; mm++) {
                for (int nn = 0; nn <= n; nn++) {
                    System.out.print(dp[i%2][mm][nn]+" ");
                }
                System.out.println();
            }
            System.out.println("_________________________________");
        }

        int ans = 0;
        for(int mm = 0 ; mm <= m; mm++){
            for(int nn = 0 ; nn <= n; nn++){
                ans = Math.max(ans,dp[(strs.length-1)%2][mm][nn]);
            }
        }


        return ans;

    }

    public static void main(String[] args){

        String[] s = {"10","0001","111001","1","0"};
        int m = 5, n = 3;

        int ans = findMaxForm(s,m,n);

        System.out.println(ans);

    }

}
