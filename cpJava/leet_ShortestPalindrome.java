package offl.leetcodes;

public class leet_ShortestPalindrome {

    public static class RollingHash {
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


    public static String reverseString(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static String shortestPalindrome(String s) {

        if(s.length()<2){
            return s;
        }

        //String ans = "";
        StringBuilder ansStr = new StringBuilder();
        RollingHash rh = new RollingHash(s);
        RollingHash rhb = new RollingHash(reverseString(s));

        int mxln = 1;

        //linear search of palindrome size
        for(int ln = s.length(); ln >1; ln--){
            //check iff palindrome
            int elInOne = ln/2;
            if(rh.getHash(0,elInOne -1) == rhb.getHash(s.length() - ln, s.length()-1 - ln + elInOne)){
                mxln = ln;
                break;
            }
        }

        //ans = reverseString(s.substring(mxln))+s;
        ansStr.append(reverseString(s.substring(mxln)));
        ansStr.append(s);
        return ansStr.toString();

    }

    public static void main(String[] args){

        String str = "aabbaagh";
        System.out.println(shortestPalindrome(str));



    }
}
