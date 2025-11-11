package offl.leetcodes;

public class leet_MaximumRepeatingSubstring {

    static int[] zFunction(String s) {
        int n = s.length();
        int[] z = new int[n];
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                z[i] = Math.min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
                z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
    
    public static int maxRepeating(String sequence, String word) {
        String zStr = word+"#"+sequence;
        
        int[] z = zFunction(zStr);
        int[] dp = new int[z.length+1];

        int ans = 0;
        for(int i = z.length-1; i>word.length(); i--){
            if(z[i] == word.length()){//full match after the index
                if(i+word.length() < dp.length){
                    dp[i] = dp[i+word.length()]+1;
                    ans = Math.max(ans, dp[i]);
                }
            }
        }
        return ans;
    }

    public static void main(String[] args){

        //String[] s = {"a","aba","ababa","aa"};

        String s = "ab", pattern = "abm";
        int ans = maxRepeating(s,pattern);

        System.out.println(ans);

    }
}
