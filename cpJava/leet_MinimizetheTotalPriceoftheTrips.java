package offl.contest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class leet_MinimizetheTotalPriceoftheTrips {

    static class Graph {
        int V;
        List<List<Integer>> adj;
        int[] prices;
        int[] contri;

        long[][] dp;

        Graph(int vertices, int[] prices) {
            V = vertices;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());

            this.prices = prices;
            contri = new int[V];
            dp = new long[V][2];

            for(long[] dpi:dp){
                Arrays.fill(dpi,-1);
            }

        }

        void addEdge(int u, int v) {
                adj.get(v).add(u);
                adj.get(u).add(v);
        }

        long DFSRecDP(int start) {
            boolean[] visited = new boolean[V];
            return DFSUtilDP(start, visited, false);
        }

        long DFSUtilDP(int node, boolean[] visited, boolean isParentSelected) {

            if(dp[node][(isParentSelected ?1:0)]!= -1){
                return dp[node][(isParentSelected ?1:0)];
            }

            boolean[] visitedCopy = visited.clone();
            boolean[] visitedCopy2 = visited.clone();
            visitedCopy[node] = true;
            visitedCopy2[node] = true;
            System.out.print(node + " ");

            long withSelection = Long.MAX_VALUE;
            if(!isParentSelected) {
                withSelection= (long) prices[node]/2 * (long)contri[node];
                for (int neighbor : adj.get(node)) {
                    if (!visitedCopy[neighbor]) {
                        withSelection += DFSUtilDP(neighbor, visitedCopy, true);
                    }
                }
            }

            long withoutSelection = (long) prices[node] * (long)contri[node];;
            for (int neighbor : adj.get(node)) {
                if (!visitedCopy2[neighbor]) {
                    withoutSelection += DFSUtilDP(neighbor, visitedCopy2, false);
                }
            }

            return dp[node][(isParentSelected?1:0)] = Math.min(withSelection,withoutSelection);

        }

        void DFSRecPathConriCalc(int start,int target) {
            boolean[] visited = new boolean[V];
            Stack<Integer> st = new Stack<>();
            DFSUtilPathConriCalc(start, visited,st,target);

            System.out.print(" PATH: from "+start+" to "+target+" = ");
            while(!st.empty()){
                System.out.print(st.peek()+" ");
                contri[st.pop()]++;
            }
            System.out.println();


        }

        boolean DFSUtilPathConriCalc(int node, boolean[] visited,Stack<Integer> st, int target) {
            st.push(node);
            visited[node] = true;

            if(node == target){
                return true;
            }

            boolean isFound = false;
            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                     isFound = DFSUtilPathConriCalc(neighbor, visited, st, target);
                     if(isFound){
                         return true;
                     }
                }
            }
            st.pop();
            return false;
        }


        void printContri(){
            System.out.print("Contri:");
            for(int con:contri){
                System.out.print(con+" ");
            }
            System.out.println();

            System.out.print("Prices:");
            for(int con:prices){
                System.out.print(con+" ");
            }
            System.out.println();
        }

    }


    public static int minimumTotalPrice(int n, int[][] edges, int[] price, int[][] trips) {
        Graph gr = new Graph(n,price);
        for(int[] edge:edges){
            gr.addEdge(edge[0],edge[1]);
        }

        for(int[] trip:trips){
            gr.DFSRecPathConriCalc(trip[0],trip[1]);
        }

        gr.printContri();

        int ans = 0;

        ans = (int) gr.DFSRecDP(0);

        return ans;

    }


    public static void main(String[] args){

        int n = 4;
        int[][] edges = {{0,1},{1,2},{1,3}};
        int[] price = {2,2,10,6};
        int[][] trips = {{0,3},{2,1},{2,3}};

//        int n = 2;
//        int[][] edges = {{0,1}};
//        int[] price = {2,2};
//        int[][] trips = {{0,0}};

        System.out.println("ans="+minimumTotalPrice(n,edges,price,trips));

    }
}
