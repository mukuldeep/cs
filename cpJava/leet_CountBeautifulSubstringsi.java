package offl.leetcodes;

import java.awt.*;

public class leet_CountBeautifulSubstringsi {

    public static int beautifulSubstrings(String s, int k) {

        int[] prefixVowelCnt = new int[s.length()+1];

        prefixVowelCnt[0]=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u' ){
                prefixVowelCnt[i+1] = prefixVowelCnt[i] + 1;
            }else{
                prefixVowelCnt[i+1] = prefixVowelCnt[i];
            }
        }

        int ans =0;

        for(int len = 2; len<=s.length(); len+=2){
            int reqLen = len>>1;
            if((reqLen*reqLen)%k ==0) {
                for (int i = 0; i <= s.length() - len; i++) {
                    int vow = prefixVowelCnt[i + len] - prefixVowelCnt[i];
                    System.out.println(len + " i=" + i + " endi=" + (i + len - 1) + "  vowCnt = " + vow);
                    if (vow == reqLen) {
                        //if ((vow * vow) % k == 0) {
                            ans++;
                        //}
                    }
                }
            }
        }


        return ans;

    }


    public static void main(String[] args){

//        String s = "baeyh";
//        int k = 2;

        String s = "abba";
        int k = 1;

        int ans = beautifulSubstrings(s,k);
        System.out.println("ans:"+ans);

    }
}
