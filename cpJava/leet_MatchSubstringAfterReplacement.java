package offl.leetcodes;

import java.util.HashSet;

public class leet_MatchSubstringAfterReplacement {

    void computeLPS(String pat, int[] lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < pat.length()) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
    }



    public boolean matchReplacement_LPS_issue(String s, String sub, char[][] mappings) { //O(m+n)

        int[] lps = new int[sub.length()];
        computeLPS(sub, lps);

        HashSet<String> hashSet = new HashSet<>();
        for(char[] map: mappings){
            StringBuilder str = new StringBuilder();
            str.append(map[0]);
            str.append(map[1]);
            hashSet.add(str.toString());
        }

        for(int i=0, c_match = 0; i<s.length(); ){
            if(s.charAt(i) == sub.charAt(c_match) /* actual char match */ ){
                i++;
                c_match++;
            }else{
                StringBuilder key = new StringBuilder();
                key.append(s.charAt(i));
                key.append(sub.charAt(c_match));
                if(hashSet.contains(key.toString())){/* has replaceable mapping */
                    i++;
                    c_match++;
                }else{

                    //use precomputed data
                    if(c_match > 0){
                        c_match = lps[c_match-1];
                    }else{
                        i++;
                    }
                }
            }
            if(c_match == sub.length()){
                return true;
            }

        }

        return false;

    }


    public static boolean matchReplacement(String s, String sub, char[][] mappings) { //O(m*n)
        HashSet<String> hashSet = new HashSet<>();
        for(char[] map: mappings){
            StringBuilder str = new StringBuilder();
            str.append(map[0]);
            str.append(map[1]);
            hashSet.add(str.toString());
        }

        for(int i=0; i <= s.length()-sub.length(); i++){

            boolean isMatch = true;
            for(int j=0;j<sub.length();j++){
                StringBuilder key = new StringBuilder();
                key.append(sub.charAt(j));
                key.append(s.charAt(i+j));

                if(s.charAt(i+j) != sub.charAt(j) && !hashSet.contains(key.toString())){
                    isMatch = false;
                    break;
                }
            }

            if(isMatch){
                return isMatch;
            }
        }

        return false;
    }



    public static void main(String[] args){

        String s = "";
        String sub = "";
        char[][] mappings = {

        };


        boolean ans = matchReplacement(s, sub, mappings);

        System.out.println(ans);

    }
}
