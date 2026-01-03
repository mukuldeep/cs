package offl.contestLeetBW173;

import java.util.Arrays;

public class leetBw173_Q4 {
    static final int MOD = 1_000_000_007;

    static long[] prefix(long[] arr){
        int n=arr.length;
        long[] pref=new long[n+1];
        for(int i=0;i<n;i++){
            pref[i+1] =(pref[i]+arr[i])%MOD;
        }
        return pref;
    }

    static long rSum(long[] pref,int l,int r){
        int m = pref.length - 1;
        int left = Math.max(0, l);
        int right = Math.min(m - 1, r);
        if (left > right) return 0;
        return (pref[right + 1] - pref[left] + MOD) % MOD;
    }

    public static int numberOfRoutes(String[] grid, int d) {

        int n = grid.length;
        int m = grid[0].length();
        long[] dpV=new long[m];
        long[] dpH=new long[m];

        for(int c=0;c<m;c++){
            if(grid[n-1].charAt(c)=='.')
                dpV[c] = 1;
        }

        int dx=((d>=1)?(int)Math.sqrt((long) d * d-1):-1);
        for(int r=n-1;r>=0;r--){
            if(d>0){
                long[] prefixV = prefix(dpV);
                for(int c=0;c<m;c++){
                    if(grid[r].charAt(c)=='#'){
                        dpH[c] = 0;
                        continue;
                    }
                    long sum=rSum(prefixV, c-d,c+d);
                    dpH[c]=((sum-dpV[c]+MOD)%MOD);
                }
            }
            if(r == 0) break;
            long[] nxtDpV = new long[m];
            if(dx>=0){
                long[] cm = new long[m];
                for(int c=0;c<m;c++){
                    cm[c]=((dpV[c]+dpH[c])%MOD);
                }
                long[] prefCm = prefix(cm);
                for(int c=0;c<m;c++){
                    if(grid[r-1].charAt(c)=='.'){
                        nxtDpV[c]=rSum(prefCm, c-dx,c+dx);
                    }
                }
            }
            dpV=nxtDpV;
            Arrays.fill(dpH,0);
        }

        long ans = 0;
        for(int c=0;c<m;c++)
            ans=((ans+dpV[c]+dpH[c])%MOD);
        return (int) ans;

    }


    public static void main(String[] args){

//        String[] grid = {"..","#."};
//        int d = 2;

//        String[] grid = {"#"};
//        int d = 750;

        String[] grid = {".."};
        int d = 1;

        System.out.println(numberOfRoutes(grid, d));
    }
}
