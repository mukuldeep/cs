package offl.leetcodes;

public class leet_EqualScoreSubstrings {
    public boolean scoreBalance(String s) {
        int totalSum = 0;
        for(char ch: s.toCharArray()){
            totalSum+= (ch-'a')+1;;
        }

        if((totalSum&1) == 1){
            return false;
        }
        totalSum >>=1;

        int prefixSum = 0;
        for(char ch: s.toCharArray()){
            prefixSum+= (ch-'a')+1;
            if(prefixSum==totalSum){
                return true;
            }
        }

        return false;

    }
}
