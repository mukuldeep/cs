package offl.leetcodes;

import java.util.ArrayList;
import java.util.HashMap;

public class leet_TopKFrequentElements {

    public static int[] topKFrequent(int[] nums, int k) {
        int[] ans = new int[k];

        HashMap<Integer, Integer> map = new HashMap<>();
        int mxcnt = 0;

        for(int num: nums){
            int cnt = 0;
            if(map.containsKey(num)){
                cnt = map.get(num);
            }
            cnt++;
            mxcnt = Math.max(mxcnt,cnt);
            map.put(num,cnt);
        }

        HashMap<Integer, ArrayList<Integer>> cnts = new HashMap<>();
        for(int x: map.keySet()){
            ArrayList<Integer> cnt;
            if(cnts.containsKey(map.get(x))){
                cnt = cnts.get(map.get(x));
            }else{
                cnt = new ArrayList<>();
            }
            cnt.add(x);

            cnts.put(map.get(x),cnt);
        }

        int ans_ind = 0;
        for(int i = mxcnt; i>=0 && ans_ind <k; i--){
            if(cnts.containsKey(i) && cnts.get(i).size()>0){
                for(int x: cnts.get(i)){
                    if(ans_ind < k){
                        ans[ans_ind] = x;
                        ans_ind++;
                    }else{
                        break;
                    }
                }
            }
        }



        return ans;
    }

    public static void main(String[] args){
        //int[] nums = {11,81,94,43,3};
        int[] nums = {1};
        //int[] nums = {3,2,4,2};


        int[] ans = topKFrequent(nums,1);
        for(int x: ans){
            System.out.println(x+" ");
        }

    }
}
