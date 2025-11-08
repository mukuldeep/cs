package offl.leetcodes;

import java.util.HashSet;

class RollingHash {
    private static final long MOD = 1_000_000_007L; // large prime
    private static final long BASE = 131L;          // common base for hashing

    private final long[] prefixHash;  // prefixHash[i] = hash of s[0..i-1]
    private final long[] power;       // power[i] = BASE^i % MOD
    private final int n;

    /**
     * Precomputes prefix hashes and powers in O(n)
     */
    public RollingHash(String s) {
        n = s.length();
        prefixHash = new long[n + 1];
        power = new long[n + 1];
        power[0] = 1;

        for (int i = 0; i < n; i++) {
            prefixHash[i + 1] = (prefixHash[i] * BASE + s.charAt(i)) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }
    }

    /**
     * Returns hash of substring s[l..r] (inclusive)
     * O(1) time complexity
     */
    public long getHash(int l, int r) {
        if (l < 0 || r >= n || l > r) throw new IllegalArgumentException("Invalid range");
        long hash = (prefixHash[r + 1] - (prefixHash[l] * power[r - l + 1]) % MOD + MOD) % MOD;
        return hash;
    }

    /**
     * Returns length of the string used for hashing
     */
    public int length() {
        return n;
    }
}

public class leet_DistinctEchoSubstrings {


    public static int distinctEchoSubstrings(String text) {
        int ans = 0;

        HashSet<Long> set = new HashSet<>();
        RollingHash rollingHash = new RollingHash(text);

        for(int i=0;i<text.length()-1;i++){
            int start = i;
            for(int j=1; i+2*j <= text.length(); j++) {
                int mid = i+j;
                int end = i+2*j;

                if( rollingHash.getHash(start,mid-1) == rollingHash.getHash(mid,end-1)){
                    long hash = rollingHash.getHash(start,end-1);
                    if(!set.contains(hash)){
                        ans++;
                        set.add(hash);
                    }
                }

//                System.out.println(" "+start+" "+mid+" "+end+" ");
            }

        }

        return ans;
    }



    public static void main(String[] args){
        String str = "abcabcabc";


        int ans = distinctEchoSubstrings(str);

        System.out.println("ans= "+ans);

    }
}
