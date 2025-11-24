package offl.contest;

import java.util.Arrays;

public class leet_NumberofWaysofCuttingaPizza {

    static int[][] prefixApple;
    static int[][][] dp;

    public static void prefApp(int[][] prefixApple, String[] pizza){
        prefixApple[0][0] = pizza[0].charAt(0)=='A'?1:0;
        for(int j=1; j<pizza[0].length();j++){
            prefixApple[0][j] = prefixApple[0][j-1]+ ((pizza[0].charAt(j) == 'A')?1:0);
        }
        for(int j=1; j<pizza.length;j++){
            prefixApple[j][0] = prefixApple[j-1][0]+ ((pizza[j].charAt(0) == 'A')?1:0);
        }

        for(int i=1; i<pizza.length;i++){
            for(int j=1; j<pizza[0].length();j++){
                prefixApple[i][j] = prefixApple[i-1][j]+prefixApple[i][j-1] - prefixApple[i-1][j-1] + (pizza[i].charAt(j) == 'A'?1:0);
            }
        }
    }

    public static int getApples(int _1i, int _1j, int _2i, int _2j){
        int left = _1j>0? prefixApple[_2i][_1j-1] : 0;
        int top  = _1i>0? prefixApple[_1i-1][_2j] : 0;
        int sq   = (_1i>0 && _1j>0) ? prefixApple[_1i-1][_1j-1] : 0;

        int ans = prefixApple[_2i][_2j] - left - top + sq;
        //System.out.println("("+_1i+","+_1j+") to ("+_2i+","+_2j+") = "+ans);
        return ans;//prefixApple[_2i][_2j] - left - top + sq;
    }
    public static void printTabs(int depth){
        for(int i=0;i<depth;i++){
            System.out.print("\t");
        }
    }

    public static int waysUtil(int n, int m, int i,int j, int k, int depth){
        //base cases
        if(k==0){
//            printTabs(depth);
//            System.out.println(" i="+i+" j="+j+" k="+k+" apples="+getApples(i,j,n-1,m-1));
            return (getApples(i,j,n-1,m-1)>0)?1:0;
        }
        if(getApples(i,j,n-1,m-1)==0){
            return 0;
        }

        //dp hit
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        //cut at top
        int topAns = 0;
        for(int r_i = i; r_i < n; r_i++){
            if(getApples(i,j,r_i,m-1)>0) {
                topAns += waysUtil(n, m, r_i+1, j, k - 1,depth+1);
                topAns %= 1_000_000_007;
            }
        }
        //cut at left
        int leftAns = 0;
        for(int r_j = j; r_j < m; r_j++){
            if(getApples(i,j,n-1,r_j)>0) {
                leftAns += waysUtil(n, m, i, r_j+1, k - 1,depth+1);
                leftAns %= 1_000_000_007;
            }
        }
        return dp[i][j][k] = (topAns+leftAns) % 1_000_000_007;
    }

    public static void resetDp(){
        for(int i=0; i<dp.length; i++){
            for(int j=0;j<dp[0].length;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
    }

    public static int ways(String[] pizza, int k) {
        prefixApple = new int[pizza.length][pizza[0].length()];
        prefApp(prefixApple,pizza);

        dp = new int[pizza.length+2][pizza[0].length()+2][k+2];
        resetDp();

        return waysUtil(pizza.length, pizza[0].length(),0,0,k-1,0);
    }


    public static void main(String[] args){


        //String[] pizza = {"A..","AAA","..."};
        //String[] pizza = {"A..","AA.","..."};
        //int k = 3;
        // "A..",
        // "AA.",
        // "..."


        // "..",
        // "A.",
        // ".."
        String[] pizza = {"A..","A..","..."};
        int k = 1;
        System.out.println(ways(pizza,k));



    }
}
