class Solution {

    public int mxProfRec(int i, boolean canBuy, int[] prices, int[][] dp){

        //stopping condition
        if(i==prices.length){//no expectation from last element
            return 0;
        }

        if(dp[i][canBuy?0:1] != -1){
            return dp[i][canBuy?0:1];
        }


        int profit = 0;
        if(canBuy){
            profit = Math.max(
                -prices[i]+mxProfRec(i+1, false, prices, dp), //buying current item & recurse
                mxProfRec(i+1, true, prices, dp)//not buying & recurse
            );

        }else{//have to sell
            profit = Math.max(
                prices[i]+mxProfRec(i+1, true, prices, dp), //selling current stock & recurse
                mxProfRec(i+1, false, prices, dp) //not selling
            );
        }

        return dp[i][canBuy?0:1] = profit;

    }

    public int maxProfit(int[] prices) {
        int[][] dp = new int[prices.length][2];

        for (int i = 0; i < prices.length; i++) {
            Arrays.fill(dp[i], -1);
        }

        return mxProfRec(0, true, prices, dp);
    }
}