package offl.leetcodes;

public class leet_132Pattern {

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
            while (x != root && (x == null || x.color == BLACK)) {
                OrderStatisticTree.Node p = x.parent;
                if (x == p.left) {
                    OrderStatisticTree.Node w = p.right;
                    if (w.color == RED) {
                        w.color = BLACK;
                        p.color = RED;
                        rotateLeft(p);
                        w = p.right;
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
                        w.color = p.color;
                        p.color = BLACK;
                        if (w.right != null) w.right.color = BLACK;
                        rotateLeft(p);
                        x = root;
                    }
                } else {
                    OrderStatisticTree.Node w = p.left;
                    if (w.color == RED) {
                        w.color = BLACK;
                        p.color = RED;
                        rotateRight(p);
                        w = p.left;
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

    public static boolean find132pattern(int[] nums) {

        OrderStatisticTree ost = new OrderStatisticTree();

        int[] prevSmallest = new int[nums.length];
        prevSmallest[0] = nums[0];
        for(int i=1;i<nums.length;i++){
            prevSmallest[i]=Math.min(prevSmallest[i-1],nums[i]);
        }

        ost.insert(nums[nums.length -1]);

        for(int i = nums.length-1; i>0; i--){

            if(!ost.contains(nums[i])){
                ost.insert(nums[i]);
            }

            boolean isInserting = false;
            if(!ost.contains(prevSmallest[i-1])){
                ost.insert(prevSmallest[i-1]);
                isInserting = true;
            }

            int N1 = prevSmallest[i];
            int N3 = nums[i];

            if(N1<N3) {

                int N1Ord = ost.order_of_key(N1);
                int N3Ord = ost.order_of_key(N3);

                System.out.println("N1=" + N1 + " ord:" + N1Ord + "   N3=" + N3 + " ord:" + N3Ord);

                if (Math.abs(N3Ord - N1Ord) > 1) {
                    return true;
                }
            }

            if(isInserting){
                ost.erase(prevSmallest[i-1]);
            }
        }
        return false;

    }

    public static void main(String[] args){
        int[][] arr = {
                {1,0,1,-4,-3},
                {2, 3, 4, 5, 6, 8, 7},
                {1,2,3,4},
                {3,1,4,2},
                {-1,3,2,0},
                {3,5,0,3,4}
        };

        // O(1e5 log(1e5))
        // = O(1e5 * 17)
        // = O(1e6)

        for(int[] ar: arr) {
            boolean ans = find132pattern(ar);
            System.out.println(ans);
        }

    }

}
