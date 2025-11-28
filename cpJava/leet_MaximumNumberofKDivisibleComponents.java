package offl.contest;

import java.util.ArrayList;
import java.util.List;

public class leet_MaximumNumberofKDivisibleComponents {

    static class Graph {
        int V;
        List<List<Integer>> adj;

        Graph(int vertices) {
            V = vertices;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());
        }

        void addEdge(int u, int v, boolean directed) {
            adj.get(u).add(v);
            if (!directed)
                adj.get(v).add(u);
        }

        // ===== Recursive DFS =====
        int DFSRecursive(int start, int k,int[] values) {
            boolean[] visited = new boolean[V];
            int[] ans = {0};
            DFSUtil(start, visited, k, ans, values);
            System.out.println();
            return ans[0];
        }

        long DFSUtil(int node, boolean[] visited, int k, int[] ans, int[] values) {
            visited[node] = true;
            System.out.print(node + " ");

            long sum = values[node];

            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    sum += DFSUtil(neighbor, visited, k, ans,values);
                }
            }

            if(sum%k == 0){
                System.out.println("sum="+sum);
                ans[0]++;
                sum = 0;

            }
            return sum;

        }

    }




    public static int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        Graph g = new Graph(n);

        for(int[] edge:edges){
            g.addEdge(edge[0],edge[1],false);
        }

        return g.DFSRecursive(0,k, values);
    }

    public static void main(String[] args){

//        int n = 5;
//        int[][] edges = {{0,2},{1,2},{1,3},{2,4}};
//        int[] values = {1,8,1,4,4};
//        int k = 6;

        int n = 7;
        int[][] edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
        int[] values = {3,0,6,1,5,2,1};
        int k = 3;

        System.out.println(maxKDivisibleComponents(n,edges,values,k));



    }
}
