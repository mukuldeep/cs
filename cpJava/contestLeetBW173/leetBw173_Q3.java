package offl.contestLeetBW173;

import java.util.Arrays;

public class leetBw173_Q3 {

    public int findMaxVal(int n, int[][] restrictions, int[] diff) {

        long INF = (long) 1e18;
        long[] ub = new long[n];
        Arrays.fill(ub, INF);
        ub[0] = 0;

        for(int[] r:restrictions){
            ub[r[0]] = Math.min(ub[r[0]], r[1]);
        }
        for(int i=1; i<n;i++){
            ub[i]=Math.min(ub[i], ub[i-1]+diff[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            ub[i]=Math.min(ub[i], ub[i+1]+diff[i]);
        }
        long ans=0;
        for(long v:ub){
            ans= Math.max(ans,v);
        }
        return (int)ans;

    }


    public static void main(String[] args){
        System.out.println();
    }
}
