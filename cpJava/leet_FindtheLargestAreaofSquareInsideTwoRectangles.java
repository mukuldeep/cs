class Solution {



    int maxSquareInIntersection(int[] aBL, int[] aTR, int[] bBL, int[] bTR) {

        int ix1 = Math.max(aBL[0], bBL[0]);
        int iy1 = Math.max(aBL[1], bBL[1]);

        int ix2 = Math.min(aTR[0], bTR[0]);
        int iy2 = Math.min(aTR[1], bTR[1]);

        int width  = ix2 - ix1;
        int height = iy2 - iy1;

        if (width <= 0 || height <= 0) {
            return 0;
        }

        return Math.min(width, height);
    }

    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {

        int mxSide = 0;
        for(int i=0; i<bottomLeft.length; i++){
            for(int j=i+1; j<bottomLeft.length; j++){
                mxSide = Math.max(mxSide, maxSquareInIntersection(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
            }
        }
        long ans = mxSide;
        ans*=ans;
        return ans;
        
    }
}