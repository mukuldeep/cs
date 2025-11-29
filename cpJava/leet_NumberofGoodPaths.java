package offl.contest;

import java.util.*;

public class leet_NumberofGoodPaths {

    static class DSU {
        int[] parent, rank, size;

        DSU(int n) {
            parent = new int[n + 1];
            rank = new int[n + 1];
            size = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                rank[i] = 0;
                size[i] = 1;
            }
        }

        int findParent(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if (pu == pv) return;

            if (rank[pu] < rank[pv])
                parent[pu] = pv;
            else if (rank[pv] < rank[pu])
                parent[pv] = pu;
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void unionBySize(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if (pu == pv) return;

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    }

    static class Graph {
        int V;
        List<List<Integer>> adj;
        int[] values;
        int[][] val_ind;

        HashMap<Integer, ArrayList<Integer>> val2ind;

        Graph(int vertices, int[] values) {
            V = vertices;
            this.values = values;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());

            val2ind = new HashMap<>();
            createSortedNodeByVal();
        }

        private void createSortedNodeByVal(){
            val_ind = new int[V][2];
            for(int i=0; i<V;i++){
                val_ind[i][0] = values[i];
                val_ind[i][1] = i;

                if(!val2ind.containsKey(values[i])){
                    val2ind.put(values[i],new ArrayList<>());
                }
                val2ind.get(values[i]).add(i);

            }
            Arrays.sort(val_ind, (x, y) -> {
                if (x[0] != y[0])
                    return x[0] - y[0];
                return x[1] - y[1];
            });

            for(int[] valInd: val_ind){
                System.out.println(valInd[0]+" =val["+valInd[1]+"]");
            }
        }

        public int countGoodPath(){

            DSU dsu = new DSU(V+1);
            int ans = 0;

            int prev_val = val_ind[0][0];
            int prev_start = 0;

            for(int i = 0;i<V; i++){


                if(prev_val != val_ind[i][0] ) {

                    // process prev values
                    for(int pi=prev_start; pi<i; pi++) {
                        //check if same as previous value
                        int par = dsu.findParent(val_ind[pi][1]);
                        System.out.println("\tpar of " + val_ind[pi][1] + " is " + par);
                        for (int j = pi; j >= 0 && val_ind[j][0] == val_ind[pi][0]; j--) {
                            System.out.println("\t\tprevSameVal ind " + j + " is " + dsu.findParent(val_ind[j][1]));
                            if (dsu.findParent(val_ind[j][1]) == par) {
                                ans++;
                            }
                        }
                    }

                    prev_start = i;
                    prev_val = val_ind[i][0];
                }


                System.out.println(val_ind[i][1]);
                //union adjacent smaller nodes
                for (int node : adj.get(val_ind[i][1])) {
                    System.out.println("\tunion " + node + "+" + val_ind[i][1]);
                    dsu.unionByRank(node, val_ind[i][1]);
                }


            }

            for(int pi=prev_start; pi<V; pi++) {
                //check if same as previous value
                int par = dsu.findParent(val_ind[pi][1]);
                System.out.println("\tpar of " + val_ind[pi][1] + " is " + par);
                for (int j = pi; j >= 0 && val_ind[j][0] == val_ind[pi][0]; j--) {
                    System.out.println("\t\tprevSameVal ind " + j + " is " + dsu.findParent(val_ind[j][1]));
                    if (dsu.findParent(val_ind[j][1]) == par) {
                        ans++;
                    }
                }
            }

            return ans;
        }



        void addEdge(int u, int v) {
            if(values[u] < values[v]){
                adj.get(v).add(u);
            }else if(values[u] > values[v]){
                adj.get(u).add(v);
            }else{
                adj.get(Math.max(u,v)).add(Math.min(u,v));
            }

        }


    }

    public static int numberOfGoodPaths(int[] vals, int[][] edges) {

        int ans = 0;

        Graph gr = new Graph(vals.length,vals);
        for(int[] edge: edges){
            gr.addEdge(edge[0],edge[1]);
        }

        ans = gr.countGoodPath();

        return ans;
    }

    public static void main(String[] args){

//        int[] vals = {1,3,2,1,3};
//        int[][] edges = {{0,1},{0,2},{2,3},{2,4}}; //6

//        int[] vals = {1,1,2,2,3};
//        int[][] edges = {{0,1},{1,2},{2,3},{2,4}};//7

//        int[] vals = {1};
//        int[][] edges = {};//1

//        int[] vals = {2,5,5,1,5,2,3,5,1,5};
//        int[][] edges = {{0,1},{2,1},{3,2},{3,4},{3,5},{5,6},{1,7},{8,4},{9,7}};//20

        int[] vals = { 1,1,1 };
        int[][] edges = {{0,2},{2,1}};//6


        System.out.println("ans="+numberOfGoodPaths(vals,edges));



    }
}
