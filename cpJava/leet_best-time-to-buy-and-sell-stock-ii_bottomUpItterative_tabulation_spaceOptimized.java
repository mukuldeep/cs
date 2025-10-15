class Solution {

    public int maxProfit(int[] prices){
        int[][] states = new int[2][2];
        
        //base cases
        for(int buyingChoice = 0; buyingChoice <= 1; buyingChoice++){
            states[prices.length%2][buyingChoice] = 0;
        }

        //create bottom up
        for(int i = prices.length - 1; i>=0 ; i--){
            states[i%2][1] = Math.max(
                -prices[i]+ states[(i+1)%2][0], //buying current item & recurse
                states[(i+1)%2][1]//not buying & recurse
            );

            states[i%2][0] = Math.max(
                prices[i]+states[(i+1)%2][1], //selling current stock & recurse
                states[(i+1)%2][0] //not selling
            );       
        }

        return states[0][1];

    }
}