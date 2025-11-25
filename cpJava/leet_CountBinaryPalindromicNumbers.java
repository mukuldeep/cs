package offl.contest;

import java.util.BitSet;

public class leet_CountBinaryPalindromicNumbers {

    static boolean checkIfValid(long i, int numToShift, long n){
        long rev = Long.reverse(i)>>>Long.numberOfLeadingZeros(i);
        long num = (i<<numToShift)|rev;
        return num<=n;
    }



    public static int countBinaryPalindromes(long n) {
        int[] prec = new int[] {1,2,2,3};
        if(n<prec.length){
            return prec[(int)n];
        }

        int bit_length =  64 - Long.numberOfLeadingZeros(n);
        System.out.println("bit length:"+bit_length);

        int ans = Long.bitCount(n)==1?0:1;

        int len_of_half = (int)Math.ceil(bit_length/2.0);

        for(int i=1;i<bit_length;i++){
            int halfBitLen = (int)Math.ceil(i/2.0);
            long noOfPalindrome = 1L<<(halfBitLen-1);
            ans+= noOfPalindrome;
            System.out.println("Len:"+i+" valid_palin:"+noOfPalindrome);
        }

        //rangesToCheck
        long r_s = (1L<<(len_of_half-1));
        long r_e = (1L<<(len_of_half))-1;

        int numToShift = (bit_length&1)==1?len_of_half-1:len_of_half;
        System.out.println("bitlen:"+bit_length+" halfLen:"+len_of_half+" num2Shift:"+numToShift);

        //BINARY SEARCH
        long left = r_s, right = r_e;
        while(left < right){
            long mid = (long)Math.ceil((left+right)/2.0);
            if(checkIfValid(mid,numToShift,n)){
                left = mid;
            }else{
                right = mid-1;
            }
            System.out.println("l:"+left+" r:"+right);
        }
        System.out.println("l:"+left+" r:"+right+" total:"+(right-r_s+1));

        ans += (right-r_s+1);

        // LINEAR SEARCH
//        for(long i = r_s; i <= r_e;i++){
//            long rev = Long.reverse(i)>>>Long.numberOfLeadingZeros(i);
//            long num = (i<<numToShift)|rev;
//            if(num<=n){
//                ans++;
//            }
//            //Long.toBinaryString(num);
//            System.out.println(Long.toBinaryString(i)+" "+Long.toBinaryString(num));
//        }


        return ans;
    }



    public static void main(String[] args) {

//        for(long i=0;i<10;i++){
//            int bit_length =  64 - Long.numberOfLeadingZeros(i);
//            long rev = Long.reverse(i)>>>Long.numberOfLeadingZeros(i);
//            System.out.println(i+" "+Long.reverse(i)+" "+rev);
//        }

        long n = 2;//12;//69;//262
        System.out.println(countBinaryPalindromes(n));

//        for(int i=0;i<10;i++) {
//            System.out.println(i+":"+countBinaryPalindromes(i));
//        }

    }
}
