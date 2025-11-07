package offl.leetcodes;

import java.util.HashSet;

public class ContainsDuplicate {

    public static boolean containsDuplicate(int[] nums) {

        HashSet<Integer> set = new HashSet<>();
        for(int i = 0; i<nums.length; i++){
            if(set.contains(nums[i])){
                return true;
            }
            set.add(nums[i]);
        }
        return false;

    }


    public static void main(String[] args){
        //int[] nums = {11,81,94,43,3};
        int[] nums = {71,55,82,55};
        //int[] nums = {3,2,4,2};


        containsDuplicate(nums);

    }
}
