package offl.contest;

import java.util.*;

public class leet_MaximumProfitfromTradingStockswithDiscounts {


    static class Graph {
        int[][][] dp;
        int V;
        List<List<Integer>> adj;
        int[] present;
        int[] future;
        int budget;

        Graph(int vertices,int[] present, int[] future, int budget) {
            V = vertices;
            this.present = present;
            this.future = future;
            this.budget = budget;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());
        }

        void addEdge(int u, int v, boolean directed) {
            adj.get(u).add(v);
            if (!directed)
                adj.get(v).add(u);
        }

        public int[][] dfs(int u) {
            int[][] dp = new int[budget + 1][2];
            for (int v : adj.get(u)) {
                int[][] child = dfs(v);
                int[][] next = new int[budget + 1][2];

                for (int b = 0; b <= budget; b++) {
                    for (int cb = 0; cb <= b; cb++) {
                        next[b][0] = Math.max(next[b][0], dp[b - cb][0] + child[cb][0]);
                        next[b][1] = Math.max(next[b][1], dp[b - cb][1] + child[cb][1]);
                    }
                }
                dp = next;
            }

            int[][] ans = new int[budget + 1][2];
            for (int b = 0; b <= budget; b++) {
                ans[b][0] = dp[b][0];
                if (b >= present[u]) {
                    ans[b][0] = Math.max(ans[b][0], future[u] - present[u] + dp[b - present[u]][1]);
                }
                int discounted = present[u] / 2;
                ans[b][1] = dp[b][0];
                if (b >= discounted) {
                    ans[b][1] = Math.max(ans[b][1], future[u] - discounted + dp[b - discounted][1]);
                }
            }
            return ans;
        }

    }

    public static int maxProfit(int n, int[] present, int[] future, int[][] hierarchy, int budget) {
        Graph gr = new Graph(n,present,future,budget);
        for(int[] h: hierarchy){
            gr.addEdge(h[0]-1,h[1]-1,true);
        }

        int[][] dp = gr.dfs(0);
        return dp[budget][0];

        //return gr.DFSRecursive(0,budget);
    }


    public static void main(String[] args){

//        int n = 2;
//        int[] present = {1,2};
//        int[] future = {4,3};
//        int[][] hierarchy = {{1,2}};
//        int budget = 3;
//        //5


//        int n = 3;
//        int[] present = {6,4,23};
//        int[] future = {50,48,17};
//        int[][] hierarchy = {{1,3},{1,2}};
//        int budget = 28;
//        //96

        int n = 20;
        int[] present = {1,17,1,21,2,25,17,10,23,28,9,46,18,32,34,31,49,24,23,9};
        int[] future = {29,9,14,8,12,40,6,50,45,33,22,21,2,47,16,28,18,48,15,22};
        int[][] hierarchy = {{1,3},{1,9},{1,18},{1,12},{12,15},{18,17},{1,19},{17,4},{3,16},{18,2},{3,14},{9,8},{18,11},{3,20},{20,6},{17,5},{14,7},{17,13},{20,10}};
        int budget = 11;
        //82


        int ans = maxProfit(n,present,future, hierarchy,budget);

        System.out.println("Output: " + ans);
        System.out.println();
    }
}
