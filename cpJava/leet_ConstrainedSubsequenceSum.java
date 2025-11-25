package offl.contest;

import java.util.PriorityQueue;

public class leet_ConstrainedSubsequenceSum {

    static class Pair<U, V> {
        public final U first;
        public final V second;

        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }
    }

    public static int constrainedSubsetSum(int[] nums, int k) {
        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue<>((a, b) -> b.first - a.first);
        int ans = nums[0];
        pq.add(new Pair<>(nums[0],0));

        for(int i=1; i<nums.length; i++){
            ans = Math.max(ans,nums[i]);
            while((!pq.isEmpty()) && pq.peek().second<i-k){
                pq.remove();
                //System.out.println("remove "+pq.remove());
            }
            int thisAns = nums[i]+((!pq.isEmpty())?pq.peek().first:0);
            thisAns = Math.max(thisAns, nums[i]);
            pq.add(new Pair<>(thisAns,i));
            ans = Math.max(ans,thisAns);
        }

        return ans;
    }

    public static void main(String[] args){
        int[] nums = {10,2,-10,5,20};
        int k = 2;
        System.out.println(constrainedSubsetSum(nums,k));
    }
}
