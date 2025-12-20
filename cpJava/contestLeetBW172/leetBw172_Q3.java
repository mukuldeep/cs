package offl.contestLeetBW172;

import java.util.Collections;
import java.util.PriorityQueue;

public class leetBw172_Q3 {


    public int maximumScore(int[] nums, String s) {
        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
        int score = 0;
        for(int i=0;i<nums.length;i++){
            pq.offer(nums[i]);
            if (s.charAt(i)=='1'){
                score += pq.poll();
            }
        }
        return score;
    }


    public static void main(String[] args){

    }
}
