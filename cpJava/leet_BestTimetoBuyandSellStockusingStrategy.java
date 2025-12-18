class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {

        long[] preSumWoMod = new long[prices.length+1];
        long[] preSumW1 = new long[prices.length+1];

        for(int i=1;i<=prices.length;i++){
            preSumWoMod[i] = preSumWoMod[i-1] + prices[i-1] * strategy[i-1];
            preSumW1[i] = preSumW1[i-1] + prices[i-1];
        }

        long ans = preSumWoMod[prices.length];
        int hlen = k>>1;
        
        for(int i=0; i<= prices.length - k; i++){
            long _01s = preSumWoMod[i+k] - preSumWoMod[i]; 
            long _1s  = preSumW1[i+k] - preSumW1[i+hlen];
            long candAns =  preSumWoMod[prices.length] - _01s + _1s;
            ans = Math.max(ans, candAns);
        }

        return ans;
    }
}