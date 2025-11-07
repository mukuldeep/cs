package offl.leetcodes;

import java.util.ArrayDeque;
import java.util.Deque;

public class leet_FindTheMostCompetitiveSubsequence {

    public static int[] mostCompetitive(int[] nums, int k) {
        int[] ans = new int[k];
        Deque<Integer> st = new ArrayDeque<>();

        int canDelete = nums.length - k;
        for(int x: nums){
            while(canDelete > 0 && !st.isEmpty() && st.peek() > x){
                st.pop();
                canDelete--;
            }

            st.push(x);
        }

        System.out.println("can delete:"+canDelete);

        while(canDelete > 0 && !st.isEmpty()){
            st.pop();
            canDelete--;
        }


        int  i = k-1;
        while(!st.isEmpty()){
            ans[i--] = st.pop();
        }

        return ans;
    }


    public static void main(String[] args){
        //int[] nums = {11,81,94,43,3};
        //int[] nums = {71,55,82,55};
        int[] nums = {2,4,3,3,5,4,9,6};
        int k = 4;


        int[] ans = mostCompetitive(nums, k);


        for(int x: ans){
            System.out.print(x+" ");
        }
        System.out.println();

    }
}
