package offl.contest;

public class leet_w477_A {


    public long sumAndMultiply(int n) {

        String num = String.valueOf(n);
        int nm = 0;
        int sm =0;
        for(int i=0;i<num.length();i++){
            if(num.charAt(i)-'0' > 0){
                nm*=10;
                nm+= (num.charAt(i)-'0');
                sm += (num.charAt(i)-'0');
            }
        }

        long ans = (long) nm * (long) sm;
        return ans;
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
