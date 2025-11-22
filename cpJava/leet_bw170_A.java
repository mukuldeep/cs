package offl.contest;

public class leet_bw170_A {

    public static int minimumFlips(int n) {

        int bits = 0;
        int num = n;
        while(num>0){
            bits++;
            num>>=1;
        }


        int bitsb2 = bits/2;

        System.out.println("bits="+bits+" bitb2="+bitsb2);

        int ans =0;
        for(int i=0; i<bitsb2;i++){
            System.out.println(""+(n&(1<<i))+" "+(n&(1<<(bits-i-1))));


            if( ((n&(1<<i))>0) != ((n&(1<<(bits-i-1)))>0)){
                ans++;
            }
        }

        ans<<=1;
        return ans;

    }




    public static void main(String[] args){

//        int[] nums = new int[]{2,3,4,5};
//        int[][] nums2d = new int[][]{{2,3}, {4,6}};

        int ans = minimumFlips(7);
        System.out.println("ans=" + ans);

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
