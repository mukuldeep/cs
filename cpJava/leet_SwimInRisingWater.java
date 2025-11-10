package offl.leetcodes;

import java.util.ArrayDeque;
import java.util.Deque;

public class leet_SwimInRisingWater {

    static  class Pair<U, V> {
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

    private static boolean isValidCoOrd(int n, int x, int y){
        return (x >= 0 && y >= 0 && x < n && y < n);
    }

    private static boolean canSwimToDest(int[][] grid, int t){
        boolean[][] visited = new boolean[grid.length][grid.length];
        Deque<Pair<Integer,Integer>> q = new ArrayDeque<>();
        q.push(new Pair<Integer, Integer>(0,0));
        //visited[0][0] = true;

        int[] dir_x = {1,-1,0,0};
        int[] dir_y = {0,0,1,-1};

        while(!q.isEmpty()){
            Pair<Integer,Integer> curr = q.pop();
            //System.out.println("curr "+ curr.first+","+curr.second);
            for(int i=0;i<4;i++) {
                if ( isValidCoOrd(grid.length, curr.first+dir_x[i], curr.second+dir_y[i])){
                    //System.out.println("valid! "+(curr.first+dir_x[i])+" "+(curr.second+dir_y[i]));
                    if( (!visited[curr.first+dir_x[i]][curr.second+dir_y[i]]) && grid[curr.first+dir_x[i]][curr.second+dir_y[i]] <= t ) {
                        if((curr.first+dir_x[i]) == grid.length-1 && (curr.second+dir_y[i]) == grid.length-1 ){
                            return true;
                        }
                        q.push(new Pair<Integer, Integer>(curr.first+dir_x[i],curr.second+dir_y[i]));
                    }
                }
            }
            visited[curr.first][curr.second] = true;
        }

        return false;
    }

    public static int swimInWater(int[][] grid) {

        int l = Math.max(grid[0][0], grid[grid.length-1][grid.length-1]);
        int r= (grid.length * grid.length)-1;
        int mid;// = (l+r)/2;

        while(l<r){
            mid = (l+r)/2;
            System.out.println("canSwim "+mid+" "+canSwimToDest(grid,mid));
            if(canSwimToDest(grid,mid)){//look left
                r=mid;
            }else{
                l=mid+1;
            }
        }

        System.out.println(l);
        System.out.println(r);


        return l;

    }


    public static void main(String[] args){
        int[][] mat = {
                //{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}
//                {0,1,2,3,4},
//                {24,23,22,21,5},
//                {12,13,14,15,16},
//                {11,17,18,19,20},
//                {10,9,8,7,6}

              {0}

                //{0,2},{1,3}

        };



        int ans = swimInWater(mat);

        System.out.println(ans);

    }
}
