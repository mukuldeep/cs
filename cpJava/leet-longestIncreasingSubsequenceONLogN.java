package offl.leetcodes;

import java.util.Arrays;

public class longestIncreasingSubsequenceONLogN {

    public static int lengthOfLIS(int[] nums) {

        if (nums.length == 0) return 0;
        int[] tails = new int[nums.length];
        int size = 0;
        for (int x : nums) {
            int i = Arrays.binarySearch(tails, 0, size, x);
            if (i < 0) i = -(i + 1);
            tails[i] = x;
            if (i == size) size++;
        }
        return size;
    }


    public static void main(String[] args){
        int[] nums = {1, 2, 3, 4, 7, 2, 6, 10, 13, 7, 23, 8};
        //ArrayList<Integer> list = new ArrayList<>();

        int ans = lengthOfLIS(nums);

        System.out.println(ans);
//        for (Integer el:ans) {
//            System.out.print(el+", ");
//        }
//        System.out.println();

    }
}
