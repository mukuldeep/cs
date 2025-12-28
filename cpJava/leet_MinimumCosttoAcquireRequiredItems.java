package offl.contest;

public class leet_MinimumCosttoAcquireRequiredItems {

    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long ans = 0;

        long needBoth = Math.min(need1,need2);
        ans = Math.min((long)needBoth*costBoth, (long)needBoth*(long)(cost1+cost2));

        if(need1!=needBoth){
            ans +=(long) Math.min(cost1,costBoth)*(long)(need1-needBoth);
        }

        if(need2!=needBoth){
            ans += (long)Math.min(cost2,costBoth)*(long)(need2-needBoth);
        }

        return ans;
    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;



        System.out.println();
    }

}
