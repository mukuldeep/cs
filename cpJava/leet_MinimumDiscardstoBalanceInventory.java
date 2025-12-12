package offl.contest;

import java.util.Arrays;
import java.util.HashMap;

public class leet_MinimumDiscardstoBalanceInventory {

    public static int[] fn(int[] nums, int target){

            return nums;
        }

    public int minArrivalsToDiscard(int[] arrivals, int w, int m) {

        boolean[] isKept = new boolean[arrivals.length];
        Arrays.fill(isKept, false);
        HashMap<Integer, Integer> hm = new HashMap<>();
        int cnt = 0;
        for(int i=0;i<arrivals.length;i++){
            int preInd = i-w;
            if(preInd >= 0 && isKept[preInd]==true){
                if(hm.containsKey(arrivals[preInd])){
                    if(hm.get(arrivals[preInd]) > 1){
                        hm.put(arrivals[preInd], hm.get(arrivals[preInd])-1);
                    }else{
                        hm.remove(arrivals[preInd]);
                    }
                }
            }

            if(hm.containsKey(arrivals[i]) && hm.get(arrivals[i]) >= m){
                cnt++;
            }else{
                if(hm.containsKey(arrivals[i])){
                    hm.put(arrivals[i], hm.get(arrivals[i])+1);
                }else{
                    hm.put(arrivals[i],1);
                }
                isKept[i] = true;
            }

        }

        return cnt;

    }

        public static void main(String[] args){
            long num1 = 42;

            int[] nums = {2, 7, 11, 15};
            int target = 9;

            int[] ans = fn(nums, target);
            System.out.println("Output: " + Arrays.toString(ans));

            System.out.println();
        }
}
