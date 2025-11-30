package offl.contest;

import java.util.*;

public class leet_FindMinimumDiameterAfterMergingTwoTrees {

    static class Graph {
        static class Pair {
            int node, dist;
            Pair(int n, int d) { node = n; dist = d; }
        }
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

        void addAllEdge(int[][] edges){
            for (int[] e : edges) {
                addEdge(e[0],e[1],false);
            }
        }

        public int treeDiameter() {
            Pair p1 = bfs(0);
            Pair p2 = bfs(p1.node);
            return p2.dist;
        }

        Pair bfs(int start) {
            int[] dist = new int[V];
            Arrays.fill(dist, -1);

            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            dist[start] = 0;

            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.add(v);
                    }
                }
            }

            int far = start;
            for (int i = 0; i < V; i++) {
                if (dist[i] > dist[far]) far = i;
            }

            return new Pair(far, dist[far]);
        }



    }


    public static int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {

        Graph gr1 = new Graph(edges1.length+1);
        Graph gr2 = new Graph(edges2.length+1);

        gr1.addAllEdge(edges1);
        gr2.addAllEdge(edges2);

        int dia1 = gr1.treeDiameter();
        int dia2 = gr2.treeDiameter();

        System.out.println("dia1:"+dia1+" dia2:"+dia2);

        int ans = (int)Math.ceil(dia1/2.0)+(int)Math.ceil(dia2/2.0)+1;
        ans = Math.max(ans,dia1);
        ans = Math.max(ans, dia2);

        return ans;

    }

    public static void main(String[] args){

//        int[][] edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
//        int[][] edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};

        int[][] edges1 = {{0,1},{0,2},{0,3}};
        int[][] edges2 = {{0,1}};

        System.out.println(minimumDiameterAfterMerge(edges1,edges2));
    }
}
