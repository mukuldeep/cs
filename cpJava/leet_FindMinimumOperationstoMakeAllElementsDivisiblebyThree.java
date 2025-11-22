package offl.leetcodes;

public class leet_FindMinimumOperationstoMakeAllElementsDivisiblebyThree {

    public int minimumOperations(int[] nums) {
        int ans = 0;
        for(int num: nums){
            if(num%3 != 0){
                ans++;
            }
        }
        return ans;
    }
}
