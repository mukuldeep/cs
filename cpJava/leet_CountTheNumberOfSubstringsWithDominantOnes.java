package offl.leetcodes;

import java.util.ArrayList;

public class leet_CountTheNumberOfSubstringsWithDominantOnes {


//    static long countValidSubarrays(int k, int m, int x) {
//        int aMin = Math.max(0, x - m);
//        int aMax = k;
//        if (aMin > aMax) return 0;
//        long total = 0;
//
//        long first = (long)(m + 1 - x + aMin);
//        long last  = (long)(m + 1 - x + aMax);
//
//        long countA = (long)(aMax - aMin + 1);
//
//        total = (first + last) * countA / 2;
//        return total;
//    }

     public static long countValidSubarrays(int k, int m, int x) {
        long totalPairs = (long)(k + 1) * (m + 1);
        if (x <= 0) return totalPairs;

        int aMin = Math.max(0, x - m);
        int aMax = k;
        if (aMin > aMax) return 0L;
        long total = 0L;

        int t1End = Math.min(aMax, x - 1);
        if (aMin <= t1End) {
            long countA1 = (long)(t1End - aMin + 1);
            long first = (long)(m + 1 - x + aMin);
            long last  = (long)(m + 1 - x + t1End);
            total += (first + last) * countA1 / 2;
        }

        int a2Start = Math.max(aMin, x);
        if (a2Start <= aMax) {
            long countA2 = (long)(aMax - a2Start + 1);
            total += (long)(m + 1) * countA2;
        }

        return total;
    }



    public static int numberOfSubstrings(String s) {

        ArrayList<Integer> zeroIndex = new ArrayList<>();
        int[] pref1Cnt = new int[s.length()];
        int[] pre1Cnt = new int[s.length()];
        int[] post1Cnt = new int[s.length()];

        int ans = 0;

        int cnt = 0;
        int prefCnt = 0;
        for(int i=0; i<s.length(); i++){
            pref1Cnt[i] = prefCnt;
            pre1Cnt[i] = cnt;
            if(s.charAt(i) == '1'){
                cnt++;
                prefCnt++;
            }else{
                cnt = 0;
                zeroIndex.add(i);
            }
            ans += cnt;
        }
        cnt = 0;
        for(int i = s.length()-1; i>=0; i--){
            post1Cnt[i] = cnt;
            cnt = (s.charAt(i) == '1') ? cnt+1 : 0;
        }

        int sqrt = (int)Math.sqrt(s.length())+5;
        sqrt = Math.min(sqrt,zeroIndex.size());

        System.out.println("ans only 1s = "+ans);


        for(int i=0;i<zeroIndex.size(); i++){
            for(int j = i;j< Math.min(i+sqrt, zeroIndex.size()); j++){

                int total_1_needed = (j-i+1)*(j-i+1);
                int internal_1s = pref1Cnt[zeroIndex.get(j)] - pref1Cnt[zeroIndex.get(i)];
                int x = total_1_needed - internal_1s;

                int cntThis = (int) countValidSubarrays(pre1Cnt[zeroIndex.get(i)],post1Cnt[zeroIndex.get(j)],x);
                System.out.println("i="+i+" j="+j +" 1_needed="+x);
                System.out.println("pre1cnt="+pre1Cnt[zeroIndex.get(i)]+" post1cnt="+post1Cnt[zeroIndex.get(j)]+ " cntthis = "+cntThis);

                ans += cntThis;

            }
        }

        return ans;

    }

    public static void main(String[] args){
        String s = "00011";
        //String s = "101101";


        int ans = numberOfSubstrings(s);
        System.out.println(ans);
    }


}
