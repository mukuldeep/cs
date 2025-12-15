package offl.contest;

public class leet_NumberofSmoothDescentPeriodsofaStock {

        public long getDescentPeriods(int[] prices) {
            long ans = 1, currStreak = 1;
            for(int i=1;i<prices.length;i++)
                ans += currStreak = (prices[i] == prices[i-1]-1)? currStreak+1:1;
            return ans;
        }


        public static void main(String[] args){
        }
}
