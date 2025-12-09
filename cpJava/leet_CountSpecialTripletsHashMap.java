package offl.contest;

import java.util.Arrays;
import java.util.HashMap;

public class leet_CountSpecialTripletsHashMap {
    static int MOD = 1_000_000_007;

    public int specialTriplets(int[] nums) {
        HashMap<Integer, Integer> all, pre;
        all = new HashMap<>();
        pre = new HashMap<>();

        for(int x:nums){
            if(!all.containsKey(x)){
                all.put(x,1);
            }else{
                all.put(x,1+all.get(x));
            }
        }

        int ans = 0;

        for(int x:nums){
            all.put(x,all.get(x)-1);
            if(all.get(x)<=0){
                all.remove(x);
            }

            if(all.containsKey(x) && pre.containsKey(x)){
                int sufCnt = all.get(x);
                int prfCnt = pre.get(x);
                long total = ((long) sufCnt *prfCnt)%MOD;
                ans += total;
                ans %= MOD;
            }

            if(!pre.containsKey(x)){
                pre.put(x,1);
            }else{
                pre.put(x,1+pre.get(x));
            }
        }

        return ans;
    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] ans = {0};
        System.out.println("Output: " + Arrays.toString(ans));

        System.out.println();
    }

}
