package offl.contest;

import java.util.*;

public class leet_MinimumEdgeReversalsSoEveryNodeIsReachable {

    static class Graph {
        int V;
        List<List<Integer>> adj;
        HashSet<String> dirEdges;
        HashMap<String, Integer> dp;

        Graph(int vertices) {
            V = vertices;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());
            dirEdges = new HashSet<>();
            dp = new HashMap<>();
        }

        void addEdge(int u, int v, boolean directed) {
            adj.get(u).add(v);
            if (!directed)
                adj.get(v).add(u);

            dirEdges.add(u+" "+v);
        }

        // ===== Recursive DFS =====
        int DFSRecursive(int start) {
            return DFSUtil(start, -1);
        }

        int DFSUtil(int node, int par) {
            System.out.println(node + " ");

            //dp state seen earlier
            if(dp.containsKey(par+" "+node)){
                return dp.get(par+" "+node);
            }
            //dp state already calculated earlier for the node
            if(dp.containsKey("-1 "+node) && dp.containsKey(node+" "+par)){
                int par2node = dp.get("-1 "+node) - dp.get(node+" "+par);
                if(dirEdges.contains(node+" "+par)){
                    par2node++;
                }
                dp.put(par+" "+node, par2node);
                return par2node;
            }

            int ans = ( (par== -1) || (dirEdges.contains(par+" "+node)))?0:1;
            for (int neighbor : adj.get(node)) {
                if (par != neighbor) {
                    ans += DFSUtil(neighbor, node);
                }
            }

            System.out.println(par+" -> "+node + " revEdge="+ans);

            dp.put(par+" "+node, ans);

            return ans;
        }

    }


    public static int[] minEdgeReversals(int n, int[][] edges) {
        Graph gr = new Graph(n);
        for(int[] edge: edges){
            gr.addEdge(edge[0],edge[1],false);
        }

        int[] ans = new int[n];
        for(int i=0; i<n; i++){
            ans[i] = gr.DFSRecursive(i);
        }
        //System.out.println(gr.DFSRecursive(0));
        return ans;

    }


    public static void main(String[] args){

        int n = 4;
        int[][] edges = {{2,0},{2,1},{1,3}};

        int[] ans = minEdgeReversals(n, edges);
        for(int i:ans){
            System.out.print(i+" ");
        }
        System.out.println();



    }

}
