package offl.leetcodes;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;

public class leet_RandomPickIndex {

    HashMap<Integer, ArrayList<Integer>> hm;
    Random random;

    public leet_RandomPickIndex(int[] nums) {
        random = new Random();
        hm = new HashMap<>();
        for(int i = 0; i<nums.length; i++){
            ArrayList<Integer> indexList;
            if(hm.containsKey(nums[i])){
                indexList = hm.get(nums[i]);
            }else{
                indexList = new ArrayList<>();
            }
            indexList.add(i);
            hm.put(nums[i],indexList);
        }

    }

    public int pick(int target) {
        int randIndex = random.nextInt(hm.get(target).size());
        return hm.get(target).get(randIndex);
    }
}
