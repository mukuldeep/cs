package offl.leetcodes;

public class leet_IsSubsequence {
    public static boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        while(i<s.length() && j<t.length()){
            if(s.charAt(i) == t.charAt(j)){
                i++;
            }
            j++;
        }

        return i == (s.length());

    }


    public static void main(String[] args){

        //String[] s = {"a","aba","ababa","aa"};

        String s = "abc", t = "askdbcdffg";
        boolean ans = isSubsequence(s,t);
        System.out.println(ans);


        s = "abxc";t = "askdbcdffg";
        ans = isSubsequence(s,t);
        System.out.println(ans);

    }

}
