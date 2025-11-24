package offl.contest;

import java.util.ArrayList;
import java.util.List;

public class leet_BinaryPrefixDivisibleBy5 {

    public static List<Boolean> prefixesDivBy5(int[] nums) {
        int nm = 0;
        List<Boolean> ans = new ArrayList<>();

        for(int num: nums){
            nm<<=1;
            nm+=num;
            nm%=5;
            ans.add(nm==0);
        }

        return ans;

    }


    public static void main(String[] args) {


        int[] nums = new int[]{0,1,0,1,0,0,0,0,1};
        List<Boolean> ans = prefixesDivBy5(nums);

        for(boolean an: ans) {
            System.out.println(an+" ");
        }

    }
}
