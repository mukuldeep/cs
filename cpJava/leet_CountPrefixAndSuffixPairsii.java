package offl.leetcodes;

import java.util.Arrays;
import java.util.HashMap;

public class leet_CountPrefixAndSuffixPairsii {

    static class RollingHash {
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


    public static long countPrefixSuffixPairs(String[] words) {
        //Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));

        long ans = 0;

        HashMap<Long,Long> cnt = new HashMap<>();

        for(String word: words){
            //System.out.println(word);
            RollingHash rh = new RollingHash(word);
            int thisCnt = 0;
            for(int i=0;i<word.length();i++){
                if(rh.getHash(0,i) == rh.getHash(word.length()-1-i,word.length()-1)){
                    if(cnt.containsKey(rh.getHash(0,i))){
                        ans += cnt.get(rh.getHash(0,i));
                    }
                }


            }

            if(cnt.containsKey(rh.getHash(0,word.length()-1))){
                cnt.put(rh.getHash(0,word.length()-1), cnt.get(rh.getHash(0,word.length()-1))+1);
            }else{
                cnt.put(rh.getHash(0,word.length()-1),1L);
            }

            //System.out.println(ans);



        }




        return ans;
    }

    public static void main(String[] args){

        String[] s = {"a","aba","ababa","aa"};

        long ans = countPrefixSuffixPairs(s);

        System.out.println(ans);

    }




}
