package offl.contest;

public class leet_w477_C {

    public int[] sumAndMultiply(String s, int[][] queries) {
        final long MOD = 1_000_000_007L;
        String S = s; //copying
        //prefix digit sum
        long[] prefixSum = new long[S.length()+1];
        for (int i = 0; i < S.length(); i++) {
            prefixSum[i + 1] = prefixSum[i];
            if ((S.charAt(i) - '0') !=0) {
                prefixSum[i+1] +=(S.charAt(i) - '0');
                prefixSum[i+1] %= MOD;
            }
        }

        // prefix mod num, X and counts
        long[] prefixX = new long[S.length()+1];
        int[] prefixCount = new int[S.length()+1];
        for (int i = 0; i< S.length(); i ++) {
            prefixX[i+1] = prefixX[i];
            prefixCount[i+1] = prefixCount[i];
            if ((S.charAt(i) - '0') != 0) {
                prefixX[i+1]  =(prefixX[i] * 10 + (S.charAt(i) - '0')) % MOD;
                prefixCount[i+1] ++;

            }
        }


        long[] pow10 = new long[S.length()+1];
        pow10[0] = 1;
        for (int i = 1; i <= S.length(); i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        //QUERIES
        long[] ans = new long[queries.length];
        for (int qi = 0; qi < queries.length; qi++) {
            int l = queries[qi][0];
            int r = queries[qi][1];

            long sum = (prefixSum[r+1] - prefixSum[l]+MOD) % MOD;
            int cnt = prefixCount[r+1] - prefixCount[l];
            if (cnt == 0) {
                ans[qi] = 0;
                continue;
            }
            long leftX = prefixX[l];
            long rightX = prefixX[r + 1];

            long x = (rightX - (leftX * pow10[cnt]) % MOD + MOD) % MOD;

            ans[qi] = (x * sum) % MOD;
        }

        int[] ansi = new int[queries.length];
        for(int i=0; i<ans.length;i++){
            ansi[i] = (int)ans[i];
        }
        return ansi;





    }






    public static void main(String[] args){

//        int[] nums = new int[]{2,3,4,5};
//        int[][] nums2d = new int[][]{{2,3}, {4,6}};

//        int ans = minimumFlips(7);
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
