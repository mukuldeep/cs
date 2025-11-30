package offl.contest;

public class leet_MaximumSubstringsWithDistinctStart {
    public int maxDistinct(String s) {
        boolean[] chars = new boolean[26];

        for(char ch: s.toCharArray()){
            chars[ch-'a'] = true;
        }

        int cnt = 0;
        for(boolean p: chars){
            if(p){
                cnt++;
            }
        }
        return cnt;
    }
}
