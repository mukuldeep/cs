package offl.leetcodes;

import java.util.HashSet;

public class leet_KeepMultiplyingFoundValuesbyTwo {

    public int findFinalValue(int[] nums, int original) {
        HashSet<Integer> hs = new HashSet<>();
        for(int num:nums){
            hs.add(num);
        }

        while(hs.contains(original)){
            original<<=1;
        }

        return original;

    }

}
