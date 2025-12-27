package offl.contest;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class leet_MeetingRoomsIII {


    public static int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));

        PriorityQueue<Integer> freeRooms = new PriorityQueue<>();
        for (int i = 0; i < n; i++)freeRooms.add(i);

        PriorityQueue<long[]> busyRooms = new PriorityQueue<>(
                (a, b) -> a[0] == b[0] ? Long.compare(a[1], b[1]) : Long.compare(a[0], b[0])
        );

        int[] count = new int[n];

        for (int[] meeting : meetings){
            long start = meeting[0];
            long end = meeting[1];
            long duration = end - start;

            while (!busyRooms.isEmpty() && busyRooms.peek()[0] <= start){
                freeRooms.add((int) busyRooms.poll()[1]);
            }

            if (!freeRooms.isEmpty()){
                int room = freeRooms.poll();
                busyRooms.add(new long[]{end, room});
                count[room]++;
            }else{
                long[] earliest = busyRooms.poll();
                long newEnd = earliest[0] + duration;
                int room = (int) earliest[1];
                busyRooms.add(new long[]{newEnd, room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++){
            if(count[i] > count[ans]){
                ans =i;
            }
        }
        return ans;
    }




    public static void main(String[] args){

        //int n=2;
        //int[][] meetings = {{2, 7}, {11, 15}};
        //int[][] meetings ={{0,10},{1,5},{2,7},{3,4}};

        int n =4;
        int[][] meetings = {{18,19},{3,12},{17,19},{2,13},{7,10}};


        System.out.println(mostBooked(n,meetings));


        System.out.println();
    }
}
