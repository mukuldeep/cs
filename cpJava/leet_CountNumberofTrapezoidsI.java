package offl.contest;

import java.util.HashMap;

public class leet_CountNumberofTrapezoidsI {

    static long MOD = 1_000_000_007;
    public static int countTrapezoids(int[][] points) {
        HashMap<Integer,Integer> cntMp = new HashMap<>();
        for(int[] point: points){
            if(cntMp.containsKey(point[1])) {
                cntMp.put(point[1], cntMp.get(point[1]) + 1);
            }else{
                cntMp.put(point[1],1);
            }
        }

        long sum = 0;
        long ans = 0;
        for(int k: cntMp.keySet()){
            //System.out.println(k+":"+cntMp.get(k));
            long kx = cntMp.get(k);
            long kC2 = ((kx*(kx-1))/2) % MOD;
           // long kC2 = ((cntMp.get(k)*(cntMp.get(k)-1))/2)%MOD;
            long thisAns = ( kC2 * sum ) % MOD;

            sum = ( sum + kC2 ) % MOD;
            ans = ( ans + thisAns ) % MOD;
        }

        return (int)ans;
    }

    public static void main(String[] args){

        int[][] points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
        System.out.println(countTrapezoids(points));

    }
}
