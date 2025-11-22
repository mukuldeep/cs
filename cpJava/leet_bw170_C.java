package offl.contest;

import java.util.Arrays;

public class leet_bw170_C {


    public static int[] lexSmallestNegatedPerm(int n, long target) {
        long sum = ((long)n*(long)(n+1))/2;
        if(Math.abs(target) > sum){
            return new int[]{};
        }

        int[] ans = new int[n];
        for(int i=1;i<=n;i++){
            ans[i-1]=i;
        }

        long sm = 0;
        for(int i=n-1; i>=0; i--){
            if((sum - 2L*ans[i]) >= target ){
                ans[i] = -ans[i];
                sum+= (2L*ans[i]);
            }

            sm+=ans[i];
        }


        for(int x:ans){
            System.out.print(x+" ");
        }System.out.println();


//        ArrayList<Integer> ans = new ArrayList<>();
//        HashSet<Integer> hs = new HashSet<>();
//        long diff = (sum - Math.abs(target));
//        int large_i = n;
//
//        while(diff>0 && large_i>0){
//            if((2*large_i) > diff ){
//                large_i --;
//            }else{
//                diff -= (2*large_i);
//
//                ans.add(-large_i);
//                hs.add(large_i);
//                large_i--;
//
//            }
//        }
//
//        for(int i=1; i<=n; i++){
//            if(!hs.contains(i)){
//                ans.add(i);
//            }
//        }

//        int[] ansi = new int[n];
//        for(int i=0;i<n;i++){
//            if(target>=0) {
//                ansi[i] = ans.get(i);
//            }else{
//                ansi[i] = -ans.get(i);
//            }
//            sm+=ansi[i];
//        }

        if(sm != target){
            return new int[]{};
        }

        Arrays.sort(ans);
        return ans;
    }

    public static void main(String[] args){

//        int[] nums = new int[]{2,3,4,5};
//        int[][] nums2d = new int[][]{{2,3}, {4,6}};

//        int ans = 0;//longestDupSubstring(str);
//        System.out.println("ans=" + ans);

        int n = 3, target = 0 ;
        int[] ans = lexSmallestNegatedPerm(n,target);
        for(int nm: ans) {
            System.out.print(" " + nm);
        }System.out.println();

//
//        String[] strs = {"banana"};
//        for(String str: strs) {
//            String ans = "";//longestDupSubstring(str);
//            System.out.println("ans=" + ans);
//        }

    }
}
