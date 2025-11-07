package offl.leetcodes;

import java.util.HashMap;

public class ContainsDuplicateiii {


    public static boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {

        int bucketSize = valueDiff+1;
        HashMap<Long, Long> map = new HashMap<>();


        for(int i = 0; i<nums.length; i++){

            //remove older than indexDiff
            if(i > indexDiff){
                System.out.println(i);
                long numPOld = nums[i-indexDiff-1]+1_000_000_000;
                long bucketNoOld = numPOld / bucketSize;
                map.remove(bucketNoOld);
            }

            long numP = nums[i]+1_000_000_000;

            long bucketNo = numP / bucketSize;
            //check in same bucket
            if(map.containsKey(bucketNo)){
                return true;
            }

            //check adjacent buckets
            if(map.containsKey(bucketNo-1)){
                if(Math.abs(map.get(bucketNo-1)- numP) <= valueDiff){
                    return true;
                }

            }

            if(map.containsKey(bucketNo+1)){
                if(Math.abs(map.get(bucketNo+1)- numP) <= valueDiff){
                    return true;
                }

            }

            map.put(bucketNo,numP);

        }




        return false;
    }



    public static void main(String[] args){
        //int[] nums = {11,81,94,43,3};
        int[] nums = {71,55,82,55};
        //int[] nums = {3,2,4,2};
        int indDiff = 3, valueDiff = 0;


        containsNearbyAlmostDuplicate(nums, indDiff, valueDiff);

    }
}
