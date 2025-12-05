package offl.contest;

import java.util.ArrayList;
import java.util.HashSet;

public class leet_MinimumDeletionstoMakeCharacterFrequenciesUnique {

    public static int minDeletions(String s) {
        int[] fq = new int[26];
        for(char ch : s.toCharArray()){
            fq[ch - 'a']++;
        }

        ArrayList<Integer> arr = new ArrayList<>();
        for(int f:fq){
            if(f>0){
                arr.add(f);
            }
        }

        int ans = 0;
        HashSet<Integer> xx = new HashSet<>();
        for(int i=0;i< arr.size();i++){
            if(!xx.contains(arr.get(i))){
                xx.add(arr.get(i));
            }else{
                for(int j=arr.get(i)-1; j>=0;j--){
                    if(!xx.contains(j)){
                        ans += (arr.get(i)-j);
                        if(j>0) {
                            xx.add(j);
                        }
                        break;
                    }
                }
            }
            System.out.println(arr.get(i)+" ");
        }


        return ans;
    }

    public static void main(String[] args){
        String s = "aaabbbcc";
        System.out.println(minDeletions(s));
    }

}
