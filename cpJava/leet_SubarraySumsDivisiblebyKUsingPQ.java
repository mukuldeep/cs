package offl.contest;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class leet_SubarraySumsDivisiblebyKUsingPQ {

    public static int subarraysDivByK(int[] nums, int k) {

        ArrayList<PriorityQueue<Integer>> pqArr = new ArrayList<>(k);
        for(int i=0; i<k; i++){
            pqArr.add(new PriorityQueue<>());
        }

        int prefSum = 0;
        int ans = 0;
        pqArr.get(prefSum).add(0);
        for(int i=0; i< nums.length;i++){
            //int pqrind = (i+1)%k;
            //System.out.println("pqind="+pqrind+" "+pqArr.get(((i+1)%k)).isEmpty());
            prefSum+= nums[i];
            prefSum%=k;
            prefSum+=k;
            prefSum%=k;

            if(!pqArr.get((prefSum)%k).isEmpty()){
                //int mxPrefSm = prefSum - pqArr.get((prefSum)%k).peek();
                //System.out.println(i+"=>"+pqArr.get((prefSum)%k).size());
                ans += pqArr.get((prefSum)%k).size();
            }
            pqArr.get((prefSum)%k).add(i);
        }

        return ans;


    }


    public static void main(String[] args) {

//        int[] nums = new int[]{4,5,0,-2,-3,1};
//        int k = 5;

        int[] nums = new int[]{5};
        int k = 9;

        long ans = subarraysDivByK(nums,k);
        System.out.println(ans);


    }
}
