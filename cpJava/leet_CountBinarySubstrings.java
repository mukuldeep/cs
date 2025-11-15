package offl.leetcodes;

public class leet_CountBinarySubstrings {

    public int countBinarySubstrings(String s) {
        int cnt0 = s.charAt(0) == '0'?1:0;
        int cnt1 = s.charAt(0) == '1'?1:0;

        int cnt = 0;

        char ch = s.charAt(0);
        for(int i=1; i<s.length(); i++){
            if(s.charAt(i) == '0'){
                if(ch != s.charAt(i)){//reset other cnt
                    cnt0 = 0;
                }
                cnt0++;

                if(cnt1 >= cnt0){
                    cnt++;
                }


            }else{
                if(ch != s.charAt(i)){//reset other cnt
                    cnt1 = 0;
                }
                cnt1++;

                if(cnt0 >= cnt1){
                    cnt++;
                }
            }
            ch = s.charAt(i);
        }
        return cnt;

    }


}
