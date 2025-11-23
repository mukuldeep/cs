package offl.contest;

import java.util.Arrays;

public class leet_FastestCountNumberswithUniqueDigits {


    public static int countNumbersWithUniqueDigits(int n) {
        int[] f = {1,10,91,739,5275,32491,168571,712891,2345851,5611771};
        return f[n];
    }

    public static void main(String[] args) {

        //long num1 = 10;//262

        for(int i=0;i<10;i++) {
            System.out.println(i+":"+countNumbersWithUniqueDigits(i));
        }

    }
}
