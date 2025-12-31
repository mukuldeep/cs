package offl.contest;

import java.util.ArrayDeque;
import java.util.Queue;

public class leet_LastDayWhereYouCanStillCross {
    
    private static boolean isReachable(int row, int col, int[][] cells, int day){
        int[][] grid = new int[row][col];
        int dir[][] = {{-1,0},{1,0},{-1,0},{1,0}};

        for(int d = 0; d<day; d++){
            grid[cells[d][0]-1][cells[d][1]-1] = 1;
        }

        //bfs
        Queue<Integer[]> q = new ArrayDeque<>();

        for(int i=0; i<col; i++){
            if(grid[0][i] == 0){
                Integer[] cell = new Integer[]{0,i};
                q.add(cell);
                grid[0][i] = 2;
            }
        }

        while (!q.isEmpty()){
            Integer[] cell = q.remove();

            //all 4 direction
            for(int[] dr: dir){
                int r = cell[0]+dr[0];
                int c = cell[1]+dr[1];

                if( 0<=r && r<row && 0<=c &&  c<col ) {//valid cell
                    if(grid[r][c] == 0){
                        Integer[] cell_new = new Integer[]{r,c};
                        q.add(cell_new);
                        grid[r][c] = 2;
                    }
                }
            }

        }

        for(int i=0; i<col; i++) {
            if (grid[row-1][i] == 2)
                return true;
        }

        return false;
    }


    public static int latestDayToCross(int row, int col, int[][] cells) {

        int l = 0;
        int r = row*col;

        while(l<r){

            int mid = l + (r-l)/2;
            boolean isReachableMid = isReachable(row,col,cells,mid);
            System.out.println("mid:"+mid+" isReach:"+isReachableMid);
            if(isReachableMid){
                l = mid;
            }else{
                r = mid-1;
            }
        }

        return l;
    }


    public static void main(String[] args){
        long num1 = 42;

        int row = 2, col = 2;
        int[][] cells = {{1,1},{2,1},{1,2},{2,2}};

        System.out.println("Output: " + latestDayToCross(row,col, cells));

        System.out.println();
    }



}
