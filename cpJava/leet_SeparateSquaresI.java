class Solution {

    private double areaBelow(int[][] squares, double Y) {
        double area = 0;
        for (int[] s : squares) {
            double y = s[1], l = s[2];
            if (Y <= y) continue;
            if (Y >= y + l) area += l * l;
            else area += l * (Y - y);
        }
        return area;
    }
    
    public double separateSquares(int[][] squares) {
        
        double totalArea = 0;
        double low = Double.MAX_VALUE, high = Double.MIN_VALUE;

        for (int[] s : squares) {
            int y = s[1], l = s[2];
            totalArea += (double) l * l;
            low = Math.min(low, y);
            high = Math.max(high, y + l);
        }

        double target = totalArea / 2.0;

        for (int iter = 0; iter < 128; iter++) {
            double mid = (low + high) / 2;
            double below = areaBelow(squares, mid);

            if (below < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return (low + high) / 2;
    }
}