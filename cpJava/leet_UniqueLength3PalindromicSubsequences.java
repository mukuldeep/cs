package offl.leetcodes;


public class leet_UniqueLength3PalindromicSubsequences {

    public static int countPalindromicSubsequence(String s) {
        boolean[][] dp = new boolean[26][26];
        int[] suffixCnt = new int[26];
        boolean[] prefix = new boolean[26];

        for(char ch: s.toCharArray()){
            suffixCnt[ch-'a']++;
        }

        for(char ch: s.toCharArray()){
            suffixCnt[ch-'a']--;
            for(int i=0;i<26;i++){
                if(prefix[i] && suffixCnt[i]>0){
                    dp[ch-'a'][i] = true;
                }
            }
            prefix[ch-'a'] = true;
        }

        int ans = 0;

        for(boolean[] dpX: dp){
            for(boolean x:dpX){
                if(x){
                    ans++;
                }
            }
        }

        return ans;
    }

    public static void main(String[] args){

        String str = "bbcbaba";
        int ans = countPalindromicSubsequence(str);
        System.out.println("ans=" + ans);





    }
}
