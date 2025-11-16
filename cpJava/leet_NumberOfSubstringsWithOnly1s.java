package offl.leetcodes;

public class leet_NumberOfSubstringsWithOnly1s {

    public int numSub(String s) {

        int l1 = 0,ans = 0;
        for(char ch: s.toCharArray()){
            ans += l1 = (ch == '1')? l1+1:0;
            ans %= 1_000_000_007;
        }
        return ans;

    }

}
