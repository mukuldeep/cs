package offl.contest;

import java.util.*;

public class leet_Find_All_People_With_Secret {

//    static class Graph {
//        int V;
//        List<List<Integer>> adj;
//
//        Graph(int vertices) {
//            V = vertices;
//            adj = new ArrayList<>();
//            for(int i = 0; i < V; i++)
//                adj.add(new ArrayList<>());
//        }
//
//        void addEdge(int u, int v, boolean directed) {
//            adj.get(u).add(v);
//            if(!directed)
//                adj.get(v).add(u);
//        }
//
//        void DFS(int node, boolean[] visited, List<Integer> component, boolean[] isSpread, boolean[] news) {
//            visited[node] = true;
//            component.add(node);
//
//            isSpread[0] |= news[node];
//
//            for(int neighbor : adj.get(node)) {
//                if(!visited[neighbor])
//                    DFS(neighbor, visited, component, isSpread, news);
//            }
//        }
//
//        List<List<Integer>> connectedComponents(boolean[] news) {
//            boolean[] visited = new boolean[V];
//            List<List<Integer>> components = new ArrayList<>();
//
//            for(int i = 0; i < V; i++) {
//                if(!visited[i]) {
//                    List<Integer> component = new ArrayList<>();
//                    boolean[] isSpread = new boolean[]{false};
//                    DFS(i, visited, component,isSpread, news);
//                    if(isSpread[0]) {
//                        components.add(component);
//                    }
//                }
//            }
//
//            return components;
//        }
//    }


    static class DynamicDSU {
        private final Map<Integer, Integer> parent = new HashMap<>();
        private final Map<Integer, Integer> rank = new HashMap<>();

        private void makeSet(int x) {
            if (!parent.containsKey(x)) {
                parent.put(x, x);
                rank.put(x, 0);
            }
        }

        public int find(int x) {
            makeSet(x);
            if (parent.get(x) != x) {
                parent.put(x, find(parent.get(x)));
            }
            return parent.get(x);
        }

        public void union(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;

            int ra = rank.get(pa);
            int rb = rank.get(pb);

            if (ra < rb) parent.put(pa, pb);
            else if (ra > rb) parent.put(pb, pa);
            else {
                parent.put(pb, pa);
                rank.put(pa, ra + 1);
            }
        }

        public Map<Integer, List<Integer>> getComponents() {
            Map<Integer, List<Integer>> components = new HashMap<>();
            for (int x : parent.keySet()) {
                int root = find(x);
                components.computeIfAbsent(root, k -> new ArrayList<>()).add(x);
            }
            return components;
        }
    }


    public static List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {

        HashMap<Integer,ArrayList<Integer[]>> hm = new HashMap<>();
        HashSet<Integer> set = new HashSet<>();

        for(int[] meeting: meetings){
            set.add(meeting[2]);
            Integer[] meet = new Integer[]{meeting[0],meeting[1]};
            if(!hm.containsKey(meeting[2])){
                hm.put(meeting[2], new ArrayList<>());
            }

            hm.get(meeting[2]).add(meet);
        }

        boolean[] news = new boolean[n];
        Arrays.fill(news,false);
        news[0] = true;
        news[firstPerson] = true;

        ArrayList<Integer> setarr = new ArrayList<>(set);
        Collections.sort(setarr);
//        System.out.print("set = " );
        for(int i: setarr){
//            System.out.print(i+" ");

            DynamicDSU dsu = new DynamicDSU();
            for (Integer[] e : hm.get(i)) {
                dsu.union(e[0], e[1]);
            }
            Map<Integer, List<Integer>> components = dsu.getComponents();

            for(Integer k: components.keySet()){
                List<Integer> component = components.get(k);
                boolean isVisited = false;
                for(Integer x: component){
                    if(news[x] == true){
                        isVisited = true;
                        break;
                    }
                }
                if(isVisited){
                    for(Integer x: component){
                        news[x] = true;
                    }
                }

            }

//            Graph gr = new Graph(n);
//            for(Integer[] person : hm.get(i)){
//                gr.addEdge(person[0],person[1],false);
//            }
//            List<List<Integer>> conn = gr.connectedComponents(news);
//            for(List<Integer> comp: conn){
//                for(Integer pers : comp){
//                    news[pers] = true;
//                }
//            }
        }
//        System.out.println();


        List<Integer> ans = new ArrayList<>();
        for(int i=0;i < n;i++){
            if(news[i]){
                ans.add(i);
            }
        }
        return ans;
    }


        public static void main(String[] args){

            int n = 6;
            int[][] meetings = {{2, 4, 11},{1,2,6},{3,4,6}};
            int firstPerson = 2;

            List<Integer> ans = findAllPeople(n ,meetings, firstPerson);

            System.out.println("Output: " + Arrays.toString(ans.toArray()));

            System.out.println();

        }
}
