class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int preCnt = 0;
        int currCnt = 1;

        for(int i=1;i<s.length();i++){
            if(s[i] != s[i-1]){
                preCnt = currCnt;
                currCnt = 1;
            }else{
                currCnt++;
            }

            if(preCnt >= currCnt){
                ans++;
            }

        }

        return ans;
        
    }
};