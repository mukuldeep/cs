package offl.contestLeetBW171;

import java.util.HashMap;

public class leet_bw171_D {

    static class OrderStatisticTree {

        private static final boolean RED = true;
        private static final boolean BLACK = false;

        private class Node {
            int key;
            OrderStatisticTree.Node left, right, parent;
            boolean color = RED;
            int size = 1; // subtree size

            Node(int key) {
                this.key = key;
            }
        }

        private OrderStatisticTree.Node root = null;

        private int size(OrderStatisticTree.Node n) {
            return n == null ? 0 : n.size;
        }

        private void update(OrderStatisticTree.Node n) {
            if (n != null) {
                n.size = 1 + size(n.left) + size(n.right);
            }
        }

        // ===== ROTATIONS =====
        private void rotateLeft(OrderStatisticTree.Node x) {
            OrderStatisticTree.Node y = x.right;
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

        private void rotateRight(OrderStatisticTree.Node x) {
            OrderStatisticTree.Node y = x.left;
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
            OrderStatisticTree.Node z = new OrderStatisticTree.Node(key);
            OrderStatisticTree.Node y = null;
            OrderStatisticTree.Node x = root;

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

        private void insertFix(OrderStatisticTree.Node z) {
            while (z.parent != null && z.parent.color == RED) {
                if (z.parent == z.parent.parent.left) {
                    OrderStatisticTree.Node y = z.parent.parent.right;
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
                    OrderStatisticTree.Node y = z.parent.parent.left;
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

            OrderStatisticTree.Node z = root;
            while (z != null) {
                if (key == z.key) break;
                z.size--;   // update sizes on the way
                if (key < z.key) z = z.left;
                else z = z.right;
            }
            if (z == null) return;

            deleteNode(z);
        }

        private void transplant(OrderStatisticTree.Node u, OrderStatisticTree.Node v) {
            if (u.parent == null) root = v;
            else if (u == u.parent.left) u.parent.left = v;
            else u.parent.right = v;
            if (v != null) v.parent = u.parent;
        }

        private void deleteNode(OrderStatisticTree.Node z) {
            OrderStatisticTree.Node y = z;
            OrderStatisticTree.Node x;
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

                OrderStatisticTree.Node p = y.parent;
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
                OrderStatisticTree.Node cur = y.parent;
                while (cur != null) {
                    update(cur);
                    cur = cur.parent;
                }
            }

            if (yOriginalColor == BLACK)
                deleteFix(x);

            OrderStatisticTree.Node cur = (x != null ? x.parent : null);
            while (cur != null) {
                update(cur);
                cur = cur.parent;
            }
        }

        private void deleteFix(OrderStatisticTree.Node x) {
            if (x == null) return; //nullptr exception fix

            while (x != root && (x == null || x.color == BLACK)) {
                OrderStatisticTree.Node p = x.parent;
                if (x == p.left) {
                    OrderStatisticTree.Node w = p.right;
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
                    OrderStatisticTree.Node w = p.left;
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
            OrderStatisticTree.Node x = root;
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
            OrderStatisticTree.Node x = root;
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
            OrderStatisticTree.Node x = root;
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


    public static long minInversionCount(int[] nums, int k) {
        OrderStatisticTree ost = new OrderStatisticTree();
        long inv = 0;
        long ans = Long.MAX_VALUE;

        // Build first window
        for (int i = 0; i < k; i++) {
            int x = nums[i];
            int less = ost.order_of_key(x);//.orderOfKey(x);
            int greater = ost.size() - less;
            inv += greater;
            ost.insert(x);
        }
        ans = inv;

        System.out.println("init inv:"+inv);

        // Slide window
        for (int i = k; i < nums.length; i++) {
            int out = nums[i - k];
            int smaller = ost.order_of_key(out);
            int greater = ost.size() - smaller - 1; // subtract its own occurrences later
            inv -= smaller;                         // remove its contribution
            ost.erase(out);

            System.out.println(" out:"+out+" smaller:"+smaller+" greate="+greater+" inv="+inv);

            int in = nums[i];
            int less = ost.order_of_key(in);
            greater = ost.size() - less ;
            inv += greater;
            ost.insert(in);

            System.out.println(" in:"+in+" less:"+less+" greate="+greater+" inv="+inv);


            System.out.println(i+"=> inv:"+inv);


            ans = Math.min(ans, inv);
        }

        return ans;
    }


    public static long minInversionCountSub(int[] nums, int k) {

        HashMap<Integer,Integer> cnt = new HashMap<>();

        OrderStatisticTree ost = new OrderStatisticTree();
        long inv=0;
        long ans;

        for (int i = 0; i < k; i++){
            int x=nums[i];

            int less=ost.order_of_key(x);
            int greater=ost.size() - less - (cnt.containsKey(x)?cnt.get(x):0);
            inv+=greater;
            ost.insert(x);

            if(cnt.containsKey(x)){
                cnt.put(x,cnt.get(x)+1);
            }else{
                cnt.put(x,1);
            }

        }
        ans=inv;

        //System.out.println("init inv:"+inv);

        for (int i=k; i<nums.length;i++){
            int out = nums[i - k];
            int smaller = ost.order_of_key(out);
            inv-=smaller;
            ost.erase(out);

            if(cnt.get(out)==1){
                cnt.remove(out);
            }else{
                cnt.put(out,cnt.get(out)-1);
            }

//            System.out.println(" out:"+out+" smaller:"+smaller+" greate="+greater+" inv="+inv);

            int in=nums[i];
            int less=ost.order_of_key(in);
            int greater=ost.size() -less - (cnt.containsKey(in)?cnt.get(in):0);
            inv+=greater;
            ost.insert(in);

            if(cnt.containsKey(in)){
                cnt.put(in,cnt.get(in)+1);
            }else{
                cnt.put(in,1);
            }

//            System.out.println(" in:"+in+" less:"+less+" greate="+greater+" inv="+inv);
//            System.out.println(i+"=> inv:"+inv);
            ans = Math.min(ans, inv);
        }

        return ans;
    }

    public static void main(String[] args){


//        int[] nums = new int[]{3,1,2,5,4};
//        int k = 3;

//        int[] nums = new int[]{5,3,2,1};
//        int k = 4;

//        int[] nums = new int[]{2,1};
//        int k = 1;

//        int[] nums = new int[]{16,16,70,47,32,46,12};
//        int k = 4;

//        int k = 5;
//        int[] nums = new int[]{71,100,24,73,36,29,25,39,45,43,49,88,33,91,17,57,30,90,70,91,27,51,57,20,22,91,19,91,73,11,48,22,96,5,64};

        int k = 11;
        int[] nums = new int[]{60,82,95,21,44,49,83,87,19,98,14,54,42,66,39,39,56,60,80,42,87,32,7,4,18,66,35,30,52,60,82,15,77,40,11,80,7,56,99,24,94,86,56,32,42,44,49,60,28,73,16,15,77,54,78,55,45,86,68,22,4,80,97,23,52,5,73,45,52,47,4,85,57,2};

        System.out.println("Output: " + minInversionCountSub(nums,k));

        System.out.println();
    }
}
