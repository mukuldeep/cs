package offl.contest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class leet_KthSmallestPathXORSum {

    static HashMap<Integer, ArrayList<int[]>> qMap;

    static class OrderStatisticTree {

        private static final boolean RED = true;
        private static final boolean BLACK = false;

        private class Node {
            int key;
            Node left, right, parent;
            boolean color = RED;
            int size = 1; // subtree size

            Node(int key) {
                this.key = key;
            }
        }

        private Node root = null;

        private int size(Node n) {
            return n == null ? 0 : n.size;
        }

        private void update(Node n) {
            if (n != null) {
                n.size = 1 + size(n.left) + size(n.right);
            }
        }

        // ===== ROTATIONS =====
        private void rotateLeft(Node x) {
            Node y = x.right;
            x.right = y.left;
            if (y.left != null) y.left.parent = x;
            y.parent = x.parent;
            if (x.parent == null)
                root = y;
            else if (x == x.parent.left)
                x.parent.left = y;
            else
                x.parent.right = y;
            y.left = x;
            x.parent = y;

            update(x);
            update(y);
        }

        private void rotateRight(Node x) {
            Node y = x.left;
            x.left = y.right;
            if (y.right != null) y.right.parent = x;
            y.parent = x.parent;
            if (x.parent == null)
                root = y;
            else if (x == x.parent.left)
                x.parent.left = y;
            else
                x.parent.right = y;
            y.right = x;
            x.parent = y;

            update(x);
            update(y);
        }

        // ===== INSERT =====
        public void insert(int key) {
            Node z = new Node(key);
            Node y = null;
            Node x = root;

            while (x != null) {
                y = x;
                x.size++;       // update size on the way down
                if (z.key < x.key) x = x.left;
                else x = x.right;
            }

            z.parent = y;
            if (y == null) root = z;
            else if (z.key < y.key) y.left = z;
            else y.right = z;

            insertFix(z);
        }

        private void insertFix(Node z) {
            while (z.parent != null && z.parent.color == RED) {
                if (z.parent == z.parent.parent.left) {
                    Node y = z.parent.parent.right;
                    if (y != null && y.color == RED) {
                        z.parent.color = BLACK;
                        y.color = BLACK;
                        z.parent.parent.color = RED;
                        z = z.parent.parent;
                    } else {
                        if (z == z.parent.right) {
                            z = z.parent;
                            rotateLeft(z);
                        }
                        z.parent.color = BLACK;
                        z.parent.parent.color = RED;
                        rotateRight(z.parent.parent);
                    }
                } else {
                    Node y = z.parent.parent.left;
                    if (y != null && y.color == RED) {
                        z.parent.color = BLACK;
                        y.color = BLACK;
                        z.parent.parent.color = RED;
                        z = z.parent.parent;
                    } else {
                        if (z == z.parent.left) {
                            z = z.parent;
                            rotateRight(z);
                        }
                        z.parent.color = BLACK;
                        z.parent.parent.color = RED;
                        rotateLeft(z.parent.parent);
                    }
                }
            }
            root.color = BLACK;
        }

        // ===== DELETE =====
        public void erase(int key) {
            if(!contains(key)){
                return;
            }

            Node z = root;
            while (z != null) {
                if (key == z.key) break;
                z.size--;   // update sizes on the way
                if (key < z.key) z = z.left;
                else z = z.right;
            }
            if (z == null) return;

            deleteNode(z);
        }

        private void transplant(Node u, Node v) {
            if (u.parent == null) root = v;
            else if (u == u.parent.left) u.parent.left = v;
            else u.parent.right = v;
            if (v != null) v.parent = u.parent;
        }

        private void deleteNode(Node z) {
            Node y = z;
            Node x;
            boolean yOriginalColor = y.color;

            if (z.left == null) {
                x = z.right;
                transplant(z, z.right);
            } else if (z.right == null) {
                x = z.left;
                transplant(z, z.left);
            } else {
                y = z.right;
                while (y.left != null) y = y.left;
                yOriginalColor = y.color;
                x = y.right;

                Node p = y.parent;
                // update subtree sizes upwards
                while (p != z) {
                    p.size--;
                    p = p.parent;
                }

                if (y.parent != z) {
                    transplant(y, y.right);
                    y.right = z.right;
                    y.right.parent = y;
                }
                transplant(z, y);
                y.left = z.left;
                y.left.parent = y;
                y.color = z.color;

                update(y);
                Node cur = y.parent;
                while (cur != null) {
                    update(cur);
                    cur = cur.parent;
                }
            }

            if (yOriginalColor == BLACK)
                deleteFix(x);

            Node cur = (x != null ? x.parent : null);
            while (cur != null) {
                update(cur);
                cur = cur.parent;
            }
        }

        private void deleteFix(Node x) {
            if (x == null) return; //nullptr exception fix

            while (x != root && (x == null || x.color == BLACK)) {
                Node p = x.parent;
                if (x == p.left) {
                    Node w = p.right;
                    if( w == null){
                        return;
                    }
                    if (w.color == RED) {
                        w.color = BLACK;
                        p.color = RED;
                        rotateLeft(p);
                        w = p.right;
                    }
                    if(w==null){
                        return;
                    }
                    if ((w.left == null || w.left.color == BLACK) &&
                            (w.right == null || w.right.color == BLACK)) {
                        w.color = RED;
                        x = p;
                    } else {
                        if (w.right == null || w.right.color == BLACK) {
                            if (w.left != null) w.left.color = BLACK;
                            w.color = RED;
                            rotateRight(w);
                            w = p.right;
                        }
                        if(w==null){
                            return;
                        }
                        w.color = p.color;
                        p.color = BLACK;
                        if (w.right != null) w.right.color = BLACK;
                        rotateLeft(p);
                        x = root;
                    }
                } else {
                    Node w = p.left;
                    if(w==null){
                        return;
                    }
                    if (w.color == RED) {
                        w.color = BLACK;
                        p.color = RED;
                        rotateRight(p);
                        w = p.left;
                    }
                    if(w==null){
                        return;
                    }

                    if ((w.left == null || w.left.color == BLACK) &&
                            (w.right == null || w.right.color == BLACK)) {
                        w.color = RED;
                        x = p;
                    } else {
                        if (w.left == null || w.left.color == BLACK) {
                            if (w.right != null) w.right.color = BLACK;
                            w.color = RED;
                            rotateLeft(w);
                            w = p.left;
                        }
                        if(w==null){
                            return;
                        }
                        w.color = p.color;
                        p.color = BLACK;
                        if (w.left != null) w.left.color = BLACK;
                        rotateRight(p);
                        x = root;
                    }
                }
            }
            if (x != null) x.color = BLACK;
        }

        // ===== ORDER STATISTICS =====
        public int order_of_key(int key) {
            Node x = root;
            int result = 0;
            while (x != null) {
                if (key <= x.key) x = x.left;
                else {
                    result += 1 + size(x.left);
                    x = x.right;
                }
            }
            return result;
        }

        public Integer find_by_order(int k) {
            if (k < 0 || k >= size(root)) return null;
            Node x = root;
            while (x != null) {
                int leftSize = size(x.left);
                if (k < leftSize) x = x.left;
                else if (k == leftSize) return x.key;
                else {
                    k -= leftSize + 1;
                    x = x.right;
                }
            }
            return null;
        }

        public boolean contains(int key) {
            Node x = root;
            while (x != null) {
                if (key == x.key) return true;
                if (key < x.key) x = x.left;
                else x = x.right;
            }
            return false;
        }

        //added
        public int size(){
            return size(root);
        }
    }

    static class Graph {
        int V;
        List<List<Integer>> adj;
        int[] vals;

        Graph(int vertices, int[] vals) {
            V = vertices;
            adj = new ArrayList<>();
            this.vals = vals;
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());
        }

        void addEdge(int u, int v, boolean directed) {
            adj.get(u).add(v);
            if (!directed)
                adj.get(v).add(u);
        }

        // ===== Recursive DFS =====
        void DFSRecursive(int[] ans) {
            DFSUtil(0,0, ans);
        }

        OrderStatisticTree merge(OrderStatisticTree o1, OrderStatisticTree o2){

            if(o1.size()>o2.size()){
                for(int i=0;i<o2.size();i++){
                    int ostci = o2.find_by_order(i);
                    if(!o1.contains(ostci)){
                        o1.insert(ostci);
                    }
                }
                return o1;
            }

            for(int i=0;i<o1.size();i++){
                int ostci = o1.find_by_order(i);
                if(!o2.contains(ostci)){
                    o2.insert(ostci);
                }
            }
            return o2;

        }

        OrderStatisticTree DFSUtil(int node, int xorSoFar, int[] ans) {
            //System.out.print(node + " ");
            OrderStatisticTree ost = new OrderStatisticTree();
            xorSoFar = xorSoFar ^ vals[node];
            ost.insert(xorSoFar);


            for (int neighbor : adj.get(node)) {
                OrderStatisticTree ostc =  DFSUtil(neighbor, xorSoFar, ans);

                ost = merge(ost,ostc);

//                for(int i=0;i<ostc.size();i++){
//                    int ostci = ostc.find_by_order(i);
//                    if(!ost.contains(ostci)){
//                        ost.insert(ostci);
//                    }
//                }

            }

            //process queries
            if(qMap.containsKey(node)){
                for(int[] qr:qMap.get(node)){
                    if(ost.size() < qr[0]){
                        ans[qr[1]] = -1;
                    }else{
                        ans[qr[1]] = ost.find_by_order(qr[0]-1);
                    }
                }
            }

            return ost;
        }


    }



    public static int[] kthSmallest(int[] par, int[] vals, int[][] queries) {

        Graph tree = new Graph(par.length+1, vals);
        for(int i=1;i<par.length;i++){
            tree.addEdge(par[i],i,true);
        }

        int[] ans = new int[queries.length];

        //offline queries
        qMap = new HashMap<>(); //node => { [k,index], ...  }
        for(int i=0;i<queries.length;i++){
            if(!qMap.containsKey(queries[i][0])){
                qMap.put(queries[i][0], new ArrayList<>());
            }
            qMap.get(queries[i][0]).add(new int[]{queries[i][1],i});
        }

        tree.DFSRecursive(ans);

        return ans;
    }


        public static void main(String[] args){

            int[] par = {-1,0,0};
            int[] vals = {1,1,1};
            int[][] queries = {{0,1},{0,2},{0,3}};

            int[] ans = kthSmallest(par,vals,queries);

            System.out.println("Output: " + Arrays.toString(ans));
            System.out.println();
        }

}
