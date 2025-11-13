package offl.leetcodes;

public class leet_MaximumNumberOfOperationsToMoveOnesToTheEnd {

    public int maxOperations(String s) {
        int ans = 0;
        int oneCnt = 0;
        boolean isLastState0 = false;
        for(char ch: s.toCharArray()){

            if(ch=='1'){
                if(isLastState0){
                    ans+= oneCnt;
                }

                isLastState0 = false;
                oneCnt++;
            }else{
                isLastState0 = true;
            }
        }

        if(isLastState0){
            ans+= oneCnt;
        }

        return ans;

    }
}
