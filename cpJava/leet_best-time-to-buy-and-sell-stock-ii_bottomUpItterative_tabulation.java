class Solution {

    public int maxProfit(int[] prices) {
        return mxProfIttr(prices);
    }


    public int mxProfIttr(int[] prices){
        int[][] states = new int[prices.length+1][2];

        for (int i = 0; i < states.length; i++) {
            Arrays.fill(states[i], -1);
        }
        
        //base cases
        for(int buyingChoice = 0; buyingChoice <= 1; buyingChoice++){
            states[prices.length][buyingChoice] = 0;
        }

        //create bottom up
        for(int i = prices.length - 1; i>=0 ; i--){
            for(int buyingChoice = 0; buyingChoice <= 1; buyingChoice++){

                int profit = 0;
                if(buyingChoice==1){
                    profit = Math.max(
                        -prices[i]+ states[i+1][0], //buying current item & recurse
                        states[i+1][1]//not buying & recurse
                    );

                }else{//have to sell
                    profit = Math.max(
                        prices[i]+states[i+1][1], //selling current stock & recurse
                        states[i+1][0] //not selling
                    );
                }
                states[i][buyingChoice] = profit;                
            }
        }

        return states[0][1];

    }
}