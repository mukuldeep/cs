package offl.contest;

import java.util.PriorityQueue;

public class leet_SlidingWindowMaximum {

    public int[] maxSlidingWindow(int[] nums, int k) {

        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> Integer.compare(b[0], a[0])
        );

        int[] ans = new int[nums.length-k+1];

        for(int i=0;i<k-1;i++){
            pq.add(new int[]{nums[i],i});
        }

        for(int i = k-1; i<nums.length; i++){
            pq.add(new int[]{nums[i],i});
            while(pq.peek()[1] < i-k+1){
                pq.remove();
            }
            ans[i-k+1] = pq.peek()[0];
        }

        return ans;

    }

}
