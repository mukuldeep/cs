package offl.leetcodes;


import java.util.HashMap;
import java.util.HashSet;

public class leet_LongestDuplicateSubstring {

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

    static int hasDuplicateSubString(String s,RollingHash rh, int len){
        //HashSet<Long> hs = new HashSet<>();
        HashMap<Long,Integer> hm = new HashMap<>();

        for(int en=len-1; en<rh.length(); en++){
            int st = en-len+1;
            System.out.println("Len="+len+" St-En "+st+" "+en);
            long strHash = rh.getHash(st,en);

            if(hm.containsKey(strHash)){
                //check if string match
                System.out.println("str to check "+s.substring(hm.get(strHash), hm.get(strHash)+len)+" "+s.substring(st,st+len));
                if(s.substring(hm.get(strHash), hm.get(strHash)+len).equals( s.substring(st,st+len))){
                    System.out.println("equal");
                    return st;
                }
            }

            hm.put(strHash,st);

//            if(hs.contains(strHash)){
//                return st;
//            }
//            hs.add(strHash);
        }

        return -1;
    }

    public static String longestDupSubstring(String s) {
        RollingHash rollingHash = new RollingHash(s);

//        for(int xx=1;xx<rollingHash.length();xx++) {
//            int pos = hasDuplicateSubString(rollingHash, xx);
//            if (pos != -1) {
//                System.out.println("\t\thas duplicate substring at " + pos+ " size="+xx);
//            }
//        }

        int l = 1, r = rollingHash.length();
        int pos=-1;
        while(l<r){
            int mid = (l+r)/2;
            if((l+r)%2==1){
                mid++;
            }
            pos = hasDuplicateSubString(s,rollingHash, mid);
            System.out.println("duplicate substring " + pos+ " size="+mid+" l="+l+" r="+r);

            if(pos == -1){//not found
                r = mid-1;
            }else{//found
                l = mid;
            }
        }


        pos = hasDuplicateSubString(s,rollingHash, l);
        System.out.println("found at "+pos+ " len="+l+" r="+r);



        String ans = "";
        if(pos != -1){
            ans = s.substring(pos, pos+l);
        }
        return ans;
    }

    public static void main(String[] args){
        //String str = "abcdabcefghabcdij";
//        String[] strs = {"abcdabcefghabcdij","abcd","rr","tttipp", "aaallaaa" };

        String[] strs = {"banana"};

        for(String str: strs) {
            String ans = longestDupSubstring(str);
            System.out.println("ans=" + ans);
        }




    }
}
