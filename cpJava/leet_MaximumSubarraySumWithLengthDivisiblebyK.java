package offl.contest;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class leet_MaximumSubarraySumWithLengthDivisiblebyK {

    public static long maxSubarraySum(int[] nums, int k) {


        ArrayList<PriorityQueue<Long>> pqArr = new ArrayList<>(k);
        for(int i=0; i<k; i++){
            pqArr.add(new PriorityQueue<>());
        }

        long prefSum = 0;
        long ans = Long.MIN_VALUE;
        pqArr.get(0).add(prefSum);
        for(int i=0; i< nums.length;i++){
            //int pqrind = (i+1)%k;
            //System.out.println("pqind="+pqrind+" "+pqArr.get(((i+1)%k)).isEmpty());
            prefSum+= nums[i];
            if(!pqArr.get((i+1)%k).isEmpty()){
                long mxPrefSm = prefSum - pqArr.get((i+1)%k).peek();
                //System.out.println(i+"=>"+mxPrefSm);
                ans = Math.max(ans, mxPrefSm);
            }
            pqArr.get((i+1)%k).add(prefSum);
        }

        return ans;

    }


    public static void main(String[] args) {

//        int[] nums = new int[]{-1,-2,-3,-4,-5};
//        int k = 4;

//        int[] nums = new int[]{-5,1,2,-3,4};
//        int k = 2;

        int[] nums = new int[]{1,2};
        int k = 1;

        long ans = maxSubarraySum(nums,k);
        System.out.println(ans);


    }
}
