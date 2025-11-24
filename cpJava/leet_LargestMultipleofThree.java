package offl.contest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class leet_LargestMultipleofThree {

    public static String largestMultipleOfThree(int[] digits) {
        StringBuilder sb = new StringBuilder();

        int sm = 0;
        ArrayList<ArrayList<Integer>> _3num = new ArrayList<>();
        for(int i=0;i<3;i++) {
            _3num.add(new ArrayList<>());
        }

        for(int digit: digits){
            sm+=digit;
            sm%=3;
            int _mi = digit%3;
            _3num.get(_mi).add(digit);
        }
        for(int i=0;i<3;i++) {
            Collections.sort(_3num.get(i));
//            for(int u:_3num.get(i)){
//                System.out.print(u+" ");
//            }System.out.println();
        }

        if (sm == 1) {
            if (!_3num.get(1).isEmpty()) {
                _3num.get(1).remove(0);
            } else if (_3num.get(2).size() > 1) {
                _3num.get(2).remove(1);
                _3num.get(2).remove(0);
            }
        } else if (sm == 2) {
            if (!_3num.get(2).isEmpty()) {
                _3num.get(2).remove(0);
            } else if (_3num.get(1).size() > 1) {
                _3num.get(1).remove(1);
                _3num.get(1).remove(0);
            }
        }

//        for(int i=0;i<3;i++) {
//            Collections.sort(_3num.get(i));
//            for(int u:_3num.get(i)){
//                System.out.print(u+" ");
//            }System.out.println();
//        }

        int[] ans = new int[_3num.get(0).size()+_3num.get(1).size()+_3num.get(2).size()];
        int x=0;
        for(ArrayList<Integer> al: _3num){
            for(int num : al){
                ans[x]=num;
                x++;
            }
        }

        Arrays.sort(ans);
//        for(int an:ans){
//            System.out.print(an+" ");
//        }System.out.println();

        boolean otherdigit = false;
        for(int i=ans.length-1; i>=0; i--){
            char ch= Character.forDigit(ans[i],10);

            if(ans[i]==0){
                if(otherdigit || i==0){
                    sb.append(ch);
                }
            }else{
                otherdigit = true;
                sb.append(ch);
            }

        }

        return sb.toString();
    }

    public static void main(String[] args){
        //int[] nums = {1,4,5};
        //int[] nums = {8,6,7,1,0};
        int[] nums = {0,1,5,3,2,0,0};
        System.out.println(largestMultipleOfThree(nums));

    }

}
