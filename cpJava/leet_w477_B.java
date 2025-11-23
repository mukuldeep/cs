package offl.contest;

import java.util.HashMap;

public class leet_w477_B {

    public int maxBalancedSubarray(int[] nums) {
        int[] NUMS = nums;
        HashMap<String, Integer> mp = new HashMap<>();
        int xor = 0, bal = 0,mxln = 0;
        mp.put("0,0", -1);
        for (int i = 0; i < NUMS.length; i++) {
            xor ^= NUMS[i];
            if ((NUMS[i] & 1) == 0) {
                bal++;
            }else{ bal--;
            }

            String key = xor + "," + bal;
            if (mp.containsKey(key)) {
                mxln = Math.max(mxln, i - mp.get(key));
            } else {
                mp.put(key, i);
            }
        }

        return mxln;

    }



    public static void main(String[] args){

//        int[] nums = new int[]{2,3,4,5};
//        int[][] nums2d = new int[][]{{2,3}, {4,6}};

//        int ans = minimumFlips(7);
//        System.out.println("ans=" + ans);

//        int[] ans = {};//longestDupSubstring(str);
//        for(int nm: ans) {
//            System.out.println(" " + nm);
//        }System.out.println();

//
//        String[] strs = {"banana"};
//        for(String str: strs) {
//            String ans = "";//longestDupSubstring(str);
//            System.out.println("ans=" + ans);
//        }

    }
}
