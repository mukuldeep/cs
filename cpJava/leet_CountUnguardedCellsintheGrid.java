package offl.leetcodes;

import java.util.HashMap;
import java.util.HashSet;

public class leet_CountUnguardedCellsintheGrid {

    public static int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        int[][] dp = new int[m][n]; // -1 = guard 1 = wall -2 = guarded
        for(int[] guard:guards){
            dp[guard[0]][guard[1]] = -1;
        }

        for(int[] wall:walls){
            dp[wall[0]][wall[1]] = 1;
        }


        //to right
        for(int i=0; i<m; i++){
            boolean isBeingGuard = false;
            for(int j=0;j<n;j++){
                if(dp[i][j] == -1){ // guarded
//                    System.out.println("guard at "+i+" "+j);
                    isBeingGuard = true;
                    dp[i][j] = -1;
                }else if(dp[i][j] == 1){//wall
//                    System.out.println("wall at "+i+" "+j);
                    isBeingGuard = false;
                    dp[i][j] = 1;
                }else{//otherwise
                    if(isBeingGuard){
                        dp[i][j] = -2;
                    }
                }

            }
        }

        //to left
        for(int i=0; i<m; i++){
            boolean isBeingGuard = false;
            for(int j=n-1;j>=0;j--){
                if(dp[i][j] == -1){ // guarded
                    isBeingGuard = true;
                    dp[i][j] = -1;
                }else if(dp[i][j] == 1){//wall
                    isBeingGuard = false;
                    dp[i][j] = 1;
                }else{//otherwise
                    if(isBeingGuard){
                        dp[i][j] = -2;
                    }
                }

            }
        }


        //to down
        for(int j=0; j<n; j++){
            boolean isBeingGuard = false;
            for(int i=0;i<m;i++){
                if(dp[i][j] == -1){ // guarded
                    isBeingGuard = true;
                    dp[i][j] = -1;
                }else if(dp[i][j] == 1){//wall
                    isBeingGuard = false;
                    dp[i][j] = 1;
                }else{//otherwise
                    if(isBeingGuard){
                        dp[i][j] = -2;
                    }
                }

            }
        }

        //to top
        for(int j=0; j<n; j++){
            boolean isBeingGuard = false;
            for(int i=m-1;i>=0;i--){
                if(dp[i][j] == -1){ // guarded
                    isBeingGuard = true;
                    dp[i][j] = -1;
                }else if(dp[i][j] == 1){//wall
                    isBeingGuard = false;
                    dp[i][j] = 1;
                }else{//otherwise
                    if(isBeingGuard){
                        dp[i][j] = -2;
                    }
                }

            }
        }


        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(dp[i][j]==0){
                    ans++;
                }
                System.out.print(dp[i][j]+" \t");
            }System.out.println();
        }

        return ans;

    }



    public static void main(String[] args){
        int[][] guards = { {0,0}, {1,1}, {2,3} };

        //m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]

        int[][] walls = {{0,1},{2,2},{1,4}};

        int m=4,n=6;



        int ans = countUnguarded(m,n,guards,walls);

        System.out.println(ans);

    }
}
