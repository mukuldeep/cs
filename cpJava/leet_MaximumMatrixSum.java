class Solution {
    public long maxMatrixSum(int[][] matrix) {

        int mn = 1_000_000;
        int nCnt = 0;
        long sm = 0;

        for(int[] mat: matrix){
            for(int m: mat){
                if(m<0){
                    nCnt++;
                }

                sm += Math.abs(m);
                mn = Math.min(mn, Math.abs(m));
            }
        }


        if((nCnt % 2)==1){
            sm -= (2*mn);
        }

        return sm;
        
    }
}