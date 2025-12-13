package offl.contest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.regex.Pattern;

public class leet_CouponCodeValidator {

    public static int[] fn(int[] nums, int target){

            return nums;
        }

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {

        ArrayList<String[]> validData = new ArrayList<>();

        String regex = "[a-zA-Z0-9_]+";
        for(int i=0;i<isActive.length;i++){
            if(isActive[i]){
                if(!code[i].equals("") && Pattern.matches(regex, code[i]) ){
                    if(businessLine[i].equals("electronics") || businessLine[i].equals("grocery") ||
                            businessLine[i].equals("pharmacy") || businessLine[i].equals("restaurant") ){
                        String[] vData = new String[]{businessLine[i],code[i]};
                        validData.add(vData);
                    }
                }
            }
        }

        Collections.sort(validData, (a, b) -> {
            int cmp = a[0].compareTo(b[0]);
            if (cmp != 0) return cmp;
            return a[1].compareTo(b[1]);
        });

        List<String> ans = new ArrayList<>();

        for(String[] vD : validData){
            ans.add(vD[1]);
        }

        return ans;

    }


        public static void main(String[] args){
            long num1 = 42;

            int[] nums = {2, 7, 11, 15};
            int target = 9;

            int[] ans = fn(nums, target);
            System.out.println("Output: " + Arrays.toString(ans));

            System.out.println();
        }
}
