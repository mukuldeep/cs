class Solution {

    public int largestRectangleArea(int[] heights) {
        // System.out.println(Arrays.toString(heights));

        int n = heights.length;
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!stack.isEmpty() && currHeight < heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, height * width);
            }

            stack.push(i);
        }
        return maxArea;
    }


    public int maximalRectangle(char[][] matrix) {
        int[][] matrixN = new int[matrix.length][matrix[0].length];

        for(int c=0; c<matrix[0].length; c++){
            matrixN[0][c] = matrix[0][c]-'0'; 
        }

        for(int r=1; r<matrix.length; r++){
            for(int c=0; c<matrix[0].length; c++){
                if(matrix[r][c] == '1'){
                    matrixN[r][c] = 1 + matrixN[r-1][c];
                } 
            }
        }

        int ans = 0;

        for(int r=0;r<matrix.length; r++){
            //each row = histogram
            int area = largestRectangleArea(matrixN[r]);
            //System.out.println("row="+r+" area="+area);
            ans = Math.max(ans, area);
        }

        return ans;

    }
}