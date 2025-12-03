package offl.contest;

import java.util.HashMap;
import java.util.HashSet;

public class leet_CountNumberofTrapezoidsII {

    static long MOD = 1_000_000_007l;

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long modPow(long base, long exp, long mod) {
        long res = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    static long modInverseFermat(long a, long mod) {
        return modPow(a, mod - 2, mod);
    }

    static String slope(int[] a, int[] b){
        long dy,dx;

        dy = a[1] - b[1];
        dx = a[0] - b[0];

        if(dx == 0){
            return "INF";
        }

        if(dy == 0){
            return "0";
        }

        long gcdd = gcd(dy,dx);
        dy /= gcdd;
        dx /= gcdd;

        long slope = ( dy * modInverseFermat(dx,MOD) ) % MOD;

        return String.valueOf(slope);
    }

    static String calcC(String m, int[] point){
        if(m.equals("INF")){
            return "INF_x_"+point[0];
        }
        long c = (point[1] - (Long.valueOf(m)*point[0])%MOD + MOD ) % MOD;

        return String.valueOf(c);
    }


    public static int countTrapezoids(int[][] points) {

        HashMap<String,HashMap<String, HashSet<String>>> ds = new HashMap<>();

        HashMap<String,Integer> slopeLnCnt = new HashMap<>();
        HashMap<String,Integer> slopeLnCollinearCnt = new HashMap<>();



        for(int i = 0;i<points.length;i++){
            for(int j = i+1; j<points.length; j++){

                String m = slope(points[i],points[j]);
                String c = calcC(m,points[i]);
                String c2 = calcC(m,points[j]);

                System.out.println("points "+i+" "+j+"=> slope= "+m+" Cs="+c+" "+c2);

                if(!ds.containsKey(m)){
                    ds.put(m,new HashMap<>());
                }

                if(!ds.get(m).containsKey(c)){
                    ds.get(m).put(c,new HashSet<>());
                }

                ds.get(m).get(c).add(points[i][0]+","+points[i][1]);
                ds.get(m).get(c).add(points[j][0]+","+points[j][1]);

                //len
                int ln = Math.abs(points[i][0]-points[j][0])+Math.abs(points[i][1]-points[j][1]);

                String slopeLnKey = m+","+ln;
                if(!slopeLnCnt.containsKey(slopeLnKey)){
                    slopeLnCnt.put(slopeLnKey,1);
                }else{
                    slopeLnCnt.put(slopeLnKey,slopeLnCnt.get(slopeLnKey)+1);
                }

                String collKey = m+","+ln+","+c;
                if(!slopeLnCollinearCnt.containsKey(collKey)){
                    slopeLnCollinearCnt.put(collKey,1);
                }else{
                    slopeLnCollinearCnt.put(collKey,slopeLnCollinearCnt.get(collKey)+1);
                }
            }
        }

        int ans = 0;



        for(String slope: ds.keySet()){
            System.out.println("processing for slope: "+slope);

            long oneSlopeAns = 0;
            long oneSlopeSumSoFar = 0;
            for(String c: ds.get(slope).keySet()){

                System.out.print("\t");
                long thisCnt = ds.get(slope).get(c).size();
                for(String pt:ds.get(slope).get(c)){
                    System.out.print(" ("+pt+") ");
                }
                long kc2 = ((thisCnt*(thisCnt-1))/2);//%MOD;
                System.out.println(" cnt="+kc2);

                oneSlopeAns += (kc2*(oneSlopeSumSoFar));//%MOD;
                oneSlopeSumSoFar += kc2;

//                oneSlopeAns%=MOD;
//                oneSlopeSumSoFar%=MOD;

            }

            ans += oneSlopeAns;

        }



        long totalPll=0;

        for(String k: slopeLnCnt.keySet()){
            long cnt = slopeLnCnt.get(k);
            cnt = (cnt*(cnt-1))/2;
            totalPll+=cnt;
        }

        for(String k: slopeLnCollinearCnt.keySet()){
            long cnt = slopeLnCollinearCnt.get(k);
            cnt = (cnt*(cnt-1))/2;
            totalPll-= cnt;
        }

        totalPll/=2;

        System.out.println("total Pllgm = "+totalPll);


        return ans-(int)totalPll;
    }



    public static void main(String[] args){
        long num1 = 42;
        //int[][] points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};

        //int[][] points = {{34,88},{-62,-38},{26,88},{91,88},{47,-38}};

        int[][] points = {{71,-89},{-75,-89},{-9,11},{-24,-89},{-51,-89},{-77,-89},{42,11}};

        System.out.println(countTrapezoids(points));
    }
}
