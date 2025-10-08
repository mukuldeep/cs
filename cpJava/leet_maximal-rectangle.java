class Solution {

    public static int[] previousSmallerIndices(int[] arr, int n) {
        int[] result = new int[n];
        Arrays.fill(result, -1);
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                result[i] = stack.peek();
            }
            stack.push(i);
        }
        return result;
    }

    public static int[] nextSmallerIndices(int[] arr, int n) {
        int[] result = new int[n];
        Arrays.fill(result, -1);
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                result[i] = stack.peek();
            }
            stack.push(i);
        }
        return result;
    }

    public int largestRectangleArea(int[] heights) {

         int n = heights.length;
        int[] preSmaller = previousSmallerIndices(heights, n);
        int[] postSmaller = nextSmallerIndices(heights, n);
        
        int largestArea = 0; 
        
        for (int i = 0; i < n; i++) {
            int l = preSmaller[i];
            int r = postSmaller[i];
            
            if(r == -1){
                r = n;
            }
            
            int area = (r-l-1) * heights[i];
            //System.out.println(heights[i]+"area:"+area);
            largestArea = Math.max(largestArea,area);
            
        }

        return largestArea;
        
    }

    public int maximalRectangle(char[][] matrix) {

        int cols = matrix.length;
        int rows = matrix[0].length;

        int[][] histo = new int[cols][rows];
        

         for(int i_row = 0;i_row<rows; i_row++){
            if(matrix[0][i_row]=='1'){
                histo[0][i_row] = 1;
            }
         }

        int maxRectArea = largestRectangleArea(histo[0]);
        for(int i_col = 1;i_col<cols; i_col++){
            for(int i_row = 0;i_row<rows; i_row++){
                if(matrix[i_col][i_row]=='1'){
                    histo[i_col][i_row] =  histo[i_col-1][i_row] + 1;
                }    
            }

            maxRectArea = Math.max(maxRectArea, largestRectangleArea(histo[i_col]));

        }

        return maxRectArea;
    }
}