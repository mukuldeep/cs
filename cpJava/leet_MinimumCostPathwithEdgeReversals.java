package offl.contest;

import java.util.*;

public class leet_MinimumCostPathwithEdgeReversals {

    class WeightedGraph {
        int V;
        List<List<int[]>> adj; // {neighbor, weight}

        WeightedGraph(int vertices) {
            V = vertices;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());
        }

        void addEdge(int u, int v, int w) {
            adj.get(u).add(new int[]{v, w});
            adj.get(v).add(new int[]{u, 2*w});
        }

        int dijkstra(int src, int dest) {
            int[] dist = new int[V];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[src] = 0;

            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
            pq.add(new int[]{0, src}); // {distance, node}

            while (!pq.isEmpty()) {
                int[] curr = pq.poll();
                int d = curr[0], u = curr[1];

                if (d > dist[u]) continue; // stale entry

                for (int[] edge : adj.get(u)) {
                    int v = edge[0], w = edge[1];
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.add(new int[]{dist[v], v});
                    }
                }
            }

            return (dist[dest] == Integer.MAX_VALUE)?-1:dist[dest];

//            System.out.println("Shortest distances from node " + src + ":");
//            for (int i = 0; i < V; i++) {
//                if (dist[i] == Integer.MAX_VALUE) System.out.println(i + ": INF");
//                else System.out.println(i + ": " + dist[i]);
//            }
        }
    }

    public int minCost(int n, int[][] edges) {

        WeightedGraph g = new WeightedGraph(n);

        for(int[] edge: edges){
            g.addEdge(edge[0], edge[1], edge[2]);
        }

        return g.dijkstra(0,n-1);
    }


    public static void main(String[] args){

    }
}
