package offl.contest;

public class leet_MagicSquaresInGrid {


    public static boolean isValid(int[][] grid, int ii,int jj){

        boolean[] _all9 = new boolean[15];
        int[] cols = new int[3];
        int[] rows = new int[3];
        int[] dias = new int[2];

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){

                _all9[grid[ii+i][jj+j]] = true;

                cols[j] += grid[ii+i][jj+j];
                rows[i] += grid[ii+i][jj+j];

            }
        }

        dias[0] = grid[ii][jj] + grid[ii+1][jj+1] + grid[ii+2][jj+2];
        dias[1] = grid[ii+2][jj] + grid[ii+1][jj+1] + grid[ii][jj+2];


        return (
                dias[0]==dias[1]
                && dias[0] == cols[0] && dias[0] == cols[1] && dias[0] == cols[2]
                && dias[0] == rows[0] && dias[0] == rows[1] && dias[0] == rows[2]
                && _all9[1] && _all9[2] && _all9[3] && _all9[4] && _all9[5]
                && _all9[6] && _all9[7] && _all9[8] && _all9[9]
        );

    }

    public static boolean isValidFaster(int[][] grid, int ii,int jj){

        boolean[] _all9 = new boolean[15];

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                _all9[grid[ii+i][jj+j]] = true;
            }
        }

        if( !(_all9[1] && _all9[2] && _all9[3] && _all9[4] && _all9[5]
                && _all9[6] && _all9[7] && _all9[8] && _all9[9]) )
            return false;

        int[] cols = new int[3];
        int[] rows = new int[3];
        int[] dias = new int[2];

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cols[j] += grid[ii+i][jj+j];
                rows[i] += grid[ii+i][jj+j];
            }
        }

        dias[0] = grid[ii][jj] + grid[ii+1][jj+1] + grid[ii+2][jj+2];
        dias[1] = grid[ii+2][jj] + grid[ii+1][jj+1] + grid[ii][jj+2];


        return (
                dias[0]==dias[1]
                        && dias[0] == cols[0] && dias[0] == cols[1] && dias[0] == cols[2]
                        && dias[0] == rows[0] && dias[0] == rows[1] && dias[0] == rows[2]
        );

    }


    public static int numMagicSquaresInside(int[][] grid){
        int cnt = 0;

        for(int i = 0; i<grid.length-2; i++){
            for(int j = 0; j<grid[0].length-2; j++){
                if(isValidFaster(grid,i,j))
                    cnt++;
            }
        }

        return cnt;
    }



    public static void main(String[] args){

        int[][] grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};

        System.out.println(numMagicSquaresInside(grid));

        System.out.println();
    }
}
