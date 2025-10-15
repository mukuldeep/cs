class Solution {
    public int maxProfit(int k, int[] prices) {


         int[][][] states = new int[2][2][k+1];
 
        for(int buyingChoice = 0; buyingChoice < 2; buyingChoice++){
            states[prices.length&1][buyingChoice][0] = 0;
        }

        for(int transQuota = 0; transQuota < k+1; transQuota++){
            states[prices.length&1][0][transQuota] = 0;
        }

        //create bottom up
        for(int i = prices.length - 1; i>=0 ; i--){
            for(int j = 1; j < k+1; j++){
                states[i&1][1][j] = Math.max(
                    -prices[i]+ states[(i+1)&1][0][j], //buying current item & recurse 
                    states[(i+1)&1][1][j]//not buying & recurse
                );

                states[i&1][0][j] = Math.max(
                    prices[i]+states[(i+1)&1][1][j-1], //selling current stock & recurse
                    states[(i+1)&1][0][j] //not selling
                );  

            }     
        }

        int ans = states[0][1][0];
        for(int i=1; i<=k; i++){
            ans = Math.max(ans, states[0][1][i]);
        }

        return ans;
        
    }
}