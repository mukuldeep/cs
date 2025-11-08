package offl.leetcodes;

import java.util.HashSet;

public class leet_CheckIfAStringContainsAllBinaryCodesOfSizeK {



    public static boolean hasAllCodes(String s, int k) {
        if(k>s.length()){
            return false;
        }

        boolean ans = true;

        HashSet<Integer> st = new HashSet<>();
        int cnt = 0;

        int num = 0;
        for(int i=0;i<k;i++){
            num<<=1;
            if(s.charAt(i) == '1'){
                num++;
            }
        }
        //System.out.println(num);
        st.add(num);
        cnt++;


        for(int i = k; i<s.length(); i++){
            if(s.charAt(i-k) == '1'){
                num^= (1<<(k-1));
            }
            num<<=1;
            if(s.charAt(i) == '1'){
                num++;
            }

            //System.out.println(num);

            if(!st.contains(num)){
                cnt++;
            }
            st.add(num);



        }

        int total_nums = 1<<k;
        return cnt == total_nums;
    }


    public static void main(String[] args){
        int[] nums = {1,2,3,4,5,6};
        int[] patt = {1,1};
        //int[] nums = {3,2,4,2};
        String str = "01100";
        int k = 2;

        boolean ans = hasAllCodes( str,k);
        System.out.println(ans+" ");

    }


}
