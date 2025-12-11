package offl.contest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;

public class leet_MaximumPathScoreinaGrid {

    public static int[] fn(int[] nums, int target){

            return nums;
        }


    public int maxPathScore(int[][] grid, int k) {
        ArrayList<ArrayList<HashMap<Integer,Integer>>> dp = new ArrayList<>();
//        for(ArrayList<HashMap<Integer,Integer>> dpRow : dp){
//            dpRow = new ArrayList<HashMap<Integer,Integer>>(grid[0].length);
//
//        }

        for(int i=0;i<grid.length;i++){
            ArrayList<HashMap<Integer,Integer>> row = new ArrayList<>();
            for(int j=0;j<grid[0].length;j++){
                HashMap<Integer,Integer> hm = new HashMap<>();
                row.add(hm);
            }
            dp.add(row);
        }


        int[] scoreScale = new int[]{0,1,2};
        int[] costScale = new int[]{0,1,1};

        dp.get(0).get(0).put(k-costScale[grid[0][0]],scoreScale[grid[0][0]]);

        //first row
        for(int i=1;i<grid[0].length;i++){
            Set<Integer> preCost = dp.get(0).get(i-1).keySet();
            for(Integer key : preCost) {
                int preScore = dp.get(0).get(i-1).get(key);

                int thisCost = key - costScale[grid[0][i]];
                if(thisCost >=0) {
                    int thisScore = preScore + scoreScale[grid[0][i]];
                    dp.get(0).get(i).put(thisCost, thisScore);
                }
            }
        }

        //first col
        for(int i=1;i<grid.length;i++){
            Set<Integer> preCost = dp.get(i-1).get(0).keySet();
            for(Integer key : preCost) {
                int preScore = dp.get(i-1).get(0).get(key);

                int thisCost = key - costScale[grid[i][0]];
                if(thisCost >=0) {
                    int thisScore = preScore + scoreScale[grid[i][0]];
                    dp.get(i).get(0).put(thisCost, thisScore);
                }
            }
        }

        for(int r=1;r<grid.length;r++){
            for(int c=1;c<grid[0].length;c++){

                //process prev row
                Set<Integer> preRowCost = dp.get(r-1).get(c).keySet();
                for(Integer key : preRowCost) {
                    int preScore = dp.get(r-1).get(c).get(key);

                    int thisCost = key - costScale[grid[r][c]];
                    if(thisCost>=0) {
                        int thisScore = preScore + scoreScale[grid[r][c]];
                        dp.get(r).get(c).put(thisCost, thisScore);
                    }

                }


                //process prev col
                Set<Integer> preColCost = dp.get(r).get(c-1).keySet();
                for(Integer key : preColCost) {
                    int preScore = dp.get(r).get(c-1).get(key);

                    int thisCost = key - costScale[grid[r][c]];
                    if(thisCost>=0) {
                        int thisScore = preScore + scoreScale[grid[r][c]];

                        if(dp.get(r).get(c).containsKey(thisCost)){
                            thisScore = Math.max(thisScore,dp.get(r).get(c).get(thisCost));
                        }

                        dp.get(r).get(c).put(thisCost, thisScore);
                    }

                }


            }
        }

        int ansMaxScore = 0;
        for(int key: dp.get(grid.length-1).get(grid[0].length-1).keySet()){
            ansMaxScore = Math.max(ansMaxScore,dp.get(grid.length-1).get(grid[0].length-1).get(key));
        }

        return ansMaxScore;
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
