class Solution {

    private boolean isValid(String[] strs, int from, int to){
        for(int i=0;i<strs.length;i++){
            if(strs[i].charAt(from) > strs[i].charAt(to)){
                return false;
            }
        }

        return true;
    }
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        int[] dp = new int[m];
        Arrays.fill(dp,-1);

        int ans = 0;

        for(int i=m-1; i>=0;i--){
            dp[i] = 1;

            for(int j=i+1; j<m; j++){
                if(isValid(strs,i,j)){
                    dp[i] = Math.max(dp[i], 1+dp[j]);
                }
            }

            ans = Math.max(ans,dp[i]);
        }

        return m-ans;
    }
}