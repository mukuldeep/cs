package offl.contest;

import java.util.Arrays;
import java.util.HashMap;

public class leet_CountCoveredBuildings {

    public static int[] fn(int[] nums, int target){

            return nums;
        }

    public int countCoveredBuildings(int n, int[][] buildings) {

        HashMap<Integer,int[]> rows, cols;
        rows = new HashMap<>();
        cols = new HashMap<>();

        for(int[] building: buildings){
            if(!rows.containsKey(building[0])){
                rows.put(building[0],new int[]{building[1],building[1]});
            }else{
                int[] pre = rows.get(building[0]);
                pre[0] = Math.min(pre[0],building[1]);
                pre[1] = Math.max(pre[1],building[1]);
                rows.put(building[0],pre);
            }

            if(!cols.containsKey(building[1])){
                cols.put(building[1],new int[] {building[0],building[0]});
            }else{
                int[] pre = cols.get(building[1]);
                pre[0] = Math.min(pre[0],building[0]);
                pre[1] = Math.max(pre[1],building[0]);
                cols.put(building[1],pre);
            }
        }

        int cnt = 0;
        for(int[] building: buildings){
            int[] rowx = rows.get(building[0]);
            int[] colx = cols.get(building[1]);

            if(rowx[0] < building[1] && building[1] < rowx[1] && colx[0] < building[0] && building[0] < colx[1]){
                cnt++;
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
