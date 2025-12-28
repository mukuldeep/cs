class Solution {
	
	//optimized O(m+n)
    public int countNegatives(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int r = rows - 1, c = 0;
        int count = 0;

        while (r >= 0 && c < cols) {
            if (grid[r][c] < 0) {
                count += cols - c;
                r--;
            } else {
                c++;
            }
        }
        return count;
    }
	
	
	// bitwise optimization O(m*n)
    public int countNegatives(int[][] grid) {
        int ans =0;
        for(int[] row : grid){
            for(int col : row){
                ans += ((col >> 31) & 1);
            }
        }
        return ans;
    }

	//brute O(ans) <= O(m*n)
	public int countNegatives(int[][] grid) {
        int ans =0;

        for(int row=grid.length-1; row >= 0; row--){
            for(int col = grid[0].length-1; col>=0;col--){
                if(grid[row][col]<0){
                    ans++;
                }else{
                    break;
                }

            }
        }
        return ans;
    }
}