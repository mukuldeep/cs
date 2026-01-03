package offl.contestLeetBW173;

import java.util.HashMap;

public class leetBw173_Q2 {

    public int minLength(int[] nums, int k) {

        HashMap<Integer,Integer> fq=new HashMap<>();
        int sm=0;
        int left=0;
        int ans=Integer.MAX_VALUE;

        for(int r=0;r<nums.length;r++){
            int x=nums[r];
            fq.put(x, fq.getOrDefault(x, 0)+1);
            if(fq.get(x)==1){
                sm+=x;
            }
            while(sm>=k){
                ans=Math.min(ans, r-left+1);
                int y=nums[left];
                fq.put(y,fq.get(y)-1);
                if (fq.get(y)==0){
                    sm-=y;
                }
                left++;
            }
        }
        return (ans==Integer.MAX_VALUE)?-1:ans;

    }


    public static void main(String[] args){
        System.out.println();
    }
}
