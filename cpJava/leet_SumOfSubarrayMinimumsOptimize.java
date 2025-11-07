package offl.leetcodes;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

public class SumOfSubarrayMinimumsOptimize {

    public static int sumSubarrayMins(int[] arr) {
        long ans = 0;
        long MOD = 1_000_000_007L;

        Deque<Integer> st = new ArrayDeque<>();

        //Stack<Integer> st = new Stack<>(),stInd = new Stack<>();
        int[] prevSmaller = new int[arr.length];
        //int[] nextSmaller = new int[arr.length];
        int nextSm;


        for(int i=0; i<arr.length; i++){
            while(!st.isEmpty() && arr[st.peek()]>=arr[i]){
                st.pop();
            }
            prevSmaller[i] = st.isEmpty()? -1 : st.peek();
            st.push(i);
        }

        st.clear();

        for(int i=arr.length-1; i>=0; i--){
            while(!st.isEmpty() && arr[st.peek()]>arr[i]){
                st.pop();
            }

            nextSm = st.isEmpty()? arr.length : st.peek();

//            nextSmaller[i] = nextSm;

//            System.out.println(arr[i]+" prev:"+prevSmaller[i]+" next:"+nextSmaller[i]);

//            long nextElements = nextSm - i;
//            long prevElements = i - prevSmaller[i];
            long totalSubStrings = ((long)(nextSm - i) * (long)(i - prevSmaller[i])) % 1_000_000_007 ; //nextElements * prevElements;
            ans +=( (totalSubStrings * arr[i]) % 1_000_000_007);
            ans %= 1_000_000_007;
//            System.out.println("prevCnt:"+prevElements+"  nextCnt:"+nextElements+" totalSubstr:"+totalSubStrings);


            st.push(i);

        }


//        System.out.println();
//        System.out.print("prevSmaller:");
//        for(int i=0; i<arr.length; i++) {
//            System.out.print(prevSmaller[i]+" ");
//        }
//        System.out.println();
//        System.out.print("nextSmaller:");
//        for(int i=0; i<arr.length; i++) {
//            System.out.print(nextSmaller[i]+" ");
//        }
//
        System.out.println("ans:"+ans);

        return (int)ans;
    }

    public static void main(String[] args){
        //int[] nums = {11,81,94,43,3};
        int[] nums = {71,55,82,55};
        //int[] nums = {3,2,4,2};


        sumSubarrayMins(nums);

    }
}
