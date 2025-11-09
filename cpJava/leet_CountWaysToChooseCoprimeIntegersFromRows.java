package offl.leetcodes;

import java.util.HashMap;

public class leet_CountWaysToChooseCoprimeIntegersFromRows {

    long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int countCoprime(int[][] mat) {

        HashMap<Long, Long>[] hm = new HashMap[2];
        hm[0] = new HashMap<>();
        hm[1] = new HashMap<>();

        for(int j = 0; j<mat[0].length; j++){
            if(hm[0].containsKey((long)mat[0][j])){
                hm[0].put((long)mat[0][j], hm[0].get((long)mat[0][j])+1L);
            }else{
                hm[0].put((long)mat[0][j], 1L);
            }
        }

        for(int i=1;i<mat.length;i++){
            int hmSelect = i%2;
            int hmSelectOther = (i+1)%2;
            for(int j = 0; j<mat[0].length; j++){
                for(long x: hm[hmSelectOther].keySet()){
                    long gcdL = gcd(x,mat[i][j]);
                    long cnt;
                    if(hm[hmSelect].containsKey(gcdL)){
                        cnt = (hm[hmSelect].get(gcdL)+hm[hmSelectOther].get(x)) % 1_000_000_007;
                    }else{
                        cnt = hm[hmSelectOther].get(x) % 1_000_000_000;
                    }
                    hm[hmSelect].put(gcdL, cnt);
                }
            }

            hm[hmSelectOther].clear();


        }

        long ans = hm[(mat.length-1)%2].containsKey(1L)?hm[(mat.length-1)%2].get(1L):0;


        return (int)ans;


    }


}
