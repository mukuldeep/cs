package offl.leetcodes;

import java.util.Arrays;

public class leet_PartitionArraySuchThatMaximumDifferenceIsK {

    public static int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int p_s = 0;
        int ans = 0;

        for(int i = 0; i<nums.length; i++){
            if(nums[i] - nums[p_s] > k){
                ans++;
                p_s = i;
            }
        }
        ans++;

        return ans;

    }


    public static void main(String[] args){
        int[] arr = {1,6,3,2,5,4};
        int k=2;

        int ans = partitionArray(arr,k);
        System.out.println("ans:"+ans);
    }
}
