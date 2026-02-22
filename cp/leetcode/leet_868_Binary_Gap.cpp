class Solution {
public:
    int binaryGap(int n) {
        int cnt=0, mxCnt = 0;
        while(n){
            if(n&1){
                mxCnt = max(mxCnt, cnt);
                cnt=1;
            }else if(cnt){
                cnt++;
            }
            n>>=1;
        }

        return mxCnt;
    }
};