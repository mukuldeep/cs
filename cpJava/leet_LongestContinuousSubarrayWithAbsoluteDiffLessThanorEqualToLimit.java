package offl.leetcodes;


public class leet_LongestContinuousSubarrayWithAbsoluteDiffLessThanorEqualToLimit {

    static class OrderedMultiSet {

        private static final boolean RED = true;
        private static final boolean BLACK = false;

        private class Node {
            int key, count = 1, size = 1;
            boolean color = RED;
            Node left, right, parent;
            Node(int k){ key = k; }
        }

        private Node root = null;

        private int size(Node n) { return n == null ? 0 : n.size; }
        private void update(Node n) {
            if (n != null) n.size = n.count + size(n.left) + size(n.right);
        }

        // ----------- ROTATIONS ----------
        private void rotateLeft(Node x) {
            Node y = x.right;

            x.right = y.left;
            if (y.left != null) y.left.parent = x;

            y.parent = x.parent;

            if (x.parent == null) root = y;
            else if (x == x.parent.left) x.parent.left = y;
            else x.parent.right = y;

            y.left = x;
            x.parent = y;

            update(x); update(y);
        }

        private void rotateRight(Node x) {
            Node y = x.left;

            x.left = y.right;
            if (y.right != null) y.right.parent = x;

            y.parent = x.parent;

            if (x.parent == null) root = y;
            else if (x == x.parent.right) x.parent.right = y;
            else x.parent.left = y;

            y.right = x;
            x.parent = y;

            update(x); update(y);
        }

        // ----------- INSERT ----------
        public void insert(int key) {
            Node x = root, p = null;

            // normal BST insert + update sizes
            while (x != null) {
                p = x;
                x.size++;
                if (key == x.key) {
                    x.count++;
                    update(x);
                    return;
                }
                x = (key < p.key) ? p.left : p.right;
            }

            Node z = new Node(key);
            z.parent = p;

            if (p == null) root = z;
            else if (key < p.key) p.left = z;
            else p.right = z;

            insertFix(z);
        }

        private void insertFix(Node z) {
            while (z.parent != null && z.parent.color == RED) {
                Node gp = z.parent.parent;

                if (z.parent == gp.left) {
                    Node y = gp.right;
                    if (y != null && y.color == RED) {
                        z.parent.color = BLACK;
                        y.color = BLACK;
                        gp.color = RED;
                        z = gp;
                    } else {
                        if (z == z.parent.right) {
                            z = z.parent;
                            rotateLeft(z);
                        }
                        z.parent.color = BLACK;
                        gp.color = RED;
                        rotateRight(gp);
                    }
                }

                else {
                    Node y = gp.left;
                    if (y != null && y.color == RED) {
                        z.parent.color = BLACK;
                        y.color = BLACK;
                        gp.color = RED;
                        z = gp;
                    } else {
                        if (z == z.parent.left) {
                            z = z.parent;
                            rotateRight(z);
                        }
                        z.parent.color = BLACK;
                        gp.color = RED;
                        rotateLeft(gp);
                    }
                }
            }
            root.color = BLACK;
        }

        // ----------- FIND NODE ----------
        private Node findNode(int key) {
            Node cur = root;
            while (cur != null) {
                if (key == cur.key) return cur;
                cur = key < cur.key ? cur.left : cur.right;
            }
            return null;
        }

        // ----------- ERASE ----------
        public void eraseOne(int key) {
            Node z = findNode(key);
            if (z == null) return;

            if (z.count > 1) {        // remove duplicate only
                z.count--;
                Node t = z;
                while (t != null) { update(t); t = t.parent; }
                return;
            }

            eraseNode(z);
        }

        private void eraseNode(Node z) {
            Node y = z;
            Node x;
            boolean yOriginalColor = y.color;

            Node startFixFrom = null;

            if (z.left == null) {
                x = z.right;
                transplant(z, z.right);
                startFixFrom = z.parent;
            } else if (z.right == null) {
                x = z.left;
                transplant(z, z.left);
                startFixFrom = z.parent;
            } else {
                y = z.right;
                while (y.left != null) y = y.left;

                yOriginalColor = y.color;
                x = y.right;

                if (y.parent == z) {
                    if (x != null) x.parent = y;
                    startFixFrom = y;
                } else {
                    transplant(y, y.right);
                    y.right = z.right;
                    y.right.parent = y;
                    startFixFrom = y.parent;
                }

                transplant(z, y);
                y.left = z.left;
                y.left.parent = y;
                y.color = z.color;

                update(y);
            }

            // fix sizes up the path
            Node cur = startFixFrom;
            while (cur != null) {
                update(cur);
                cur = cur.parent;
            }

            if (yOriginalColor == BLACK)
                deleteFix(x, startFixFrom);
        }

        private void transplant(Node u, Node v) {
            if (u.parent == null) root = v;
            else if (u == u.parent.left) u.parent.left = v;
            else u.parent.right = v;
            if (v != null) v.parent = u.parent;
        }

        private void deleteFix(Node x, Node parent) {
            while ((x != root) && (x == null || x.color == BLACK)) {
                if (x == (parent != null ? parent.left : null)) {
                    Node w = (parent != null ? parent.right : null);
                    if (w == null) break;

                    if (w.color == RED) {
                        w.color = BLACK;
                        parent.color = RED;
                        rotateLeft(parent);
                        w = parent.right;
                    }

                    if ((w.left == null || w.left.color == BLACK) &&
                            (w.right == null || w.right.color == BLACK)) {
                        w.color = RED;
                        x = parent;
                        parent = x.parent;
                    } else {
                        if (w.right == null || w.right.color == BLACK) {
                            if (w.left != null) w.left.color = BLACK;
                            w.color = RED;
                            rotateRight(w);
                            w = parent.right;
                        }
                        w.color = parent.color;
                        parent.color = BLACK;
                        if (w.right != null) w.right.color = BLACK;
                        rotateLeft(parent);
                        x = root;
                    }
                }

                else {
                    Node w = (parent != null ? parent.left : null);
                    if (w == null) break;

                    if (w.color == RED) {
                        w.color = BLACK;
                        parent.color = RED;
                        rotateRight(parent);
                        w = parent.left;
                    }

                    if ((w.left == null || w.left.color == BLACK) &&
                            (w.right == null || w.right.color == BLACK)) {
                        w.color = RED;
                        x = parent;
                        parent = x.parent;
                    } else {
                        if (w.left == null || w.left.color == BLACK) {
                            if (w.right != null) w.right.color = BLACK;
                            w.color = RED;
                            rotateLeft(w);
                            w = parent.left;
                        }
                        w.color = parent.color;
                        parent.color = BLACK;
                        if (w.left != null) w.left.color = BLACK;
                        rotateRight(parent);
                        x = root;
                    }
                }

                if (x == null) break;
            }

            if (x != null) x.color = BLACK;
        }

        // ----------- QUERY ----------
        public boolean contains(int key) { return findNode(key) != null; }

        public int order_of_key(int key) {
            Node x = root;
            int ans = 0;

            while (x != null) {
                if (key <= x.key) {
                    x = x.left;
                } else {
                    ans += size(x.left) + x.count;
                    x = x.right;
                }
            }
            return ans;
        }

        public Integer find_by_order(int k) {
            if (root == null || k < 0 || k >= root.size) return null;
            Node x = root;

            while (x != null) {
                int left = size(x.left);
                if (k < left) x = x.left;
                else if (k < left + x.count) return x.key;
                else { k -= left + x.count; x = x.right; }
            }
            return null;
        }

        public int size() { return root == null ? 0 : root.size; }

        public int getMaxDiff(){
            if(size()>1){
               return find_by_order(size()-1)-find_by_order(0);
            }
            return 0;
        }
    }

    public static int longestSubarray(int[] nums, int limit) {
        OrderedMultiSet ost = new OrderedMultiSet();
        int ans = 1;
        int i=0, j=1;
        ost.insert(nums[0]);

        while(i<nums.length && j<nums.length){
            System.out.println("1. i="+i+" j="+j);

            //try expanding to the right
            while( j<nums.length && ost.getMaxDiff() <= limit){
                ans = Math.max(ans,ost.size());
                System.out.println("adding:"+nums[j]);
                ost.insert(nums[j]);
                j++;
            }
            System.out.println("  |"+ost.size());
            System.out.println("2. i="+i+" j="+j);

            for(int x=0;x<ost.size();x++){
                int el = ost.find_by_order(x);
                System.out.print(x+"=>"+el+" ");
            }System.out.println();

            while(i<nums.length && ost.getMaxDiff() > limit){
                ost.eraseOne(nums[i]);
                System.out.println("removing:"+nums[i]);
                i++;
            }
            System.out.println("3. i="+i+" j="+j);

            ans = Math.max(ans,ost.size());

        }


        return ans;

    }

    public static void main(String[] args) {
//        int[] ar = {10, 1, 2, 4, 7, 2};
//        int k = 5;

        int[] ar = {4,2,2,2,4,4,2,2};
        int k = 0;



        //for(int[] ar: arr) {
        int ans = longestSubarray(ar, k);
        System.out.println(ans);
        //}
    }
}
