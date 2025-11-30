package offl.contest;

import java.util.Arrays;
import java.util.HashSet;

public class leet_NumberofPossibleSetsofClosingBranches {
    static class DSU {
        int[] parent, rank;//, size;

        DSU(int n) {
            parent = new int[n + 1];
            rank = new int[n + 1];
            //size = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                rank[i] = 0;
                //size[i] = 1;
            }
        }

        int findParent(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findParent(parent[node]); // Path Compression
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

    }

    static final int INF = 1000_000_000;

    public static void floydWarshall(int[][] dist) {
        int n = dist.length;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][k] < INF && dist[k][j] < INF) {//avoid overflow
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }

                }
            }
        }
    }


    public static int getMaxDistance(int mask, int n, int[][] graph){

        DSU connComps = new DSU(n);

        //create copy graph based on mask
        int[][] graphCopy = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(((mask&(1<<i))>0) && ((mask&(1<<j))>0) ){
                    graphCopy[i][j] = graph[i][j];
                    if(graph[i][j]!=INF) {
                        connComps.unionByRank(i, j);
                    }
                }else{
                    graphCopy[i][j] = INF;
                }

            }
        }

        HashSet<Integer> parents = new HashSet<>();
        for(int i=0;i<=n; i++){
            if( (mask&(1<<i))>0 ){
                int par = connComps.findParent(i);
                System.out.println("parent:"+par);
                parents.add(par);
            }
        }

        if(parents.size()>1){
            return INF;
        }



        //run floyd-warshall
        floydWarshall(graphCopy);

        //realize mistakes
        int maxDist = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graphCopy[i][j] != INF && i != j) {
                    maxDist = Math.max(maxDist,graphCopy[i][j]);

                    //System.out.print(graphCopy[i][j] + " ");
                }
                if(graphCopy[i][j] == INF){
                    System.out.print("INF ");
                }else {
                    System.out.print(graphCopy[i][j] + " ");
                }


            }
            System.out.println();
        }

        return maxDist;
    }



    public static int numberOfSets(int n, int maxDistance, int[][] roads) {

        //create matrix
        int[][] graph = new int[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(graph[i],INF);
        }
        for(int[] road: roads){
            graph[road[0]][road[1]] = Math.min(graph[road[0]][road[1]], road[2]);
            graph[road[1]][road[0]] = Math.min(graph[road[1]][road[0]], road[2]);
        }

        //explore possibilities
        System.out.println(" From "+0+" to "+((1<<n)-1));
        int ans = 0;
        for(int i=0;i<(1<<n); i++){
            int mxDist = getMaxDistance(i,n,graph);
            System.out.println("for "+i+" mxDist="+mxDist);
            if(mxDist <= maxDistance){
                ans++;
            }
        }

        return ans;
    }

    public static void main(String[] args){

//        int n = 3;
//        int maxDistance = 5;
//        int[][] roads = {{0,1,2},{1,2,10},{0,2,10}};


//        int n = 3, maxDistance = 5;
//        int[][] roads = {{0,1,20},{0,1,10},{1,2,2},{0,2,2}};


        int n = 3, maxDistance = 12;
        int[][] roads = {{1,0,11},{1,0,16},{0,2,13}};

        System.out.println(numberOfSets(n,maxDistance,roads));

    }
}
