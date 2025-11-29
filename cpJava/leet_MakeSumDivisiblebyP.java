package offl.contest;

import java.util.HashMap;

public class leet_MakeSumDivisiblebyP {

    public static int minSubarray(int[] nums, int p) {
        long sum = 0;
        for(int num: nums){
            sum += num;
        }
        long _2Del = sum%p;
        if(_2Del==0){
            return 0;
        }

        HashMap<Long, Integer> lastInd = new HashMap<Long, Integer>();
        lastInd.put(0L,-1);


        sum = 0;
        int ans = nums.length;
        for(int i=0;i< nums.length; i++){
            sum+=nums[i];
            sum%=p;

            long tofind = (sum-_2Del)%p;
            tofind+=p;
            tofind%=p;

            if(lastInd.containsKey(tofind)){
                ans = Math.min(ans,(i-lastInd.get(tofind)));
            }
            lastInd.put(sum,i);
        }

        if(ans==nums.length){
            ans = -1;
        }
        return ans;
    }

    public static void main(String[] args){

        int[] nums = {4,1,2,3};
        int p = 6;
        System.out.println("ans = "+minSubarray(nums, p));
    }
}
