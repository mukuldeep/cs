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
}