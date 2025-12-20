package offl.contestLeetBW172;

import java.util.HashMap;

public class leetBw172_Q1 {

    public int minOperations(int[] nums){
        int n=nums.length;
        HashMap<Integer, Integer> freq =new HashMap<>();

        for(int x:nums){
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }
        int dupCount = 0;
        for(int v : freq.values()){
            if(v>=2) dupCount++;
        }

        int ans = 0;
        int i = 0;
        while (i < n && dupCount > 0){
            ans++;
            for(int k = 0; k < 3 && i < n; k++, i++){
                int val = nums[i];
                int before = freq.get(val);
                freq.put(val, before - 1);
                if (before == 2){
                    dupCount--;
                }
            }
        }

        return ans;
    }


    public static void main(String[] args){
        System.out.println();
    }
}
