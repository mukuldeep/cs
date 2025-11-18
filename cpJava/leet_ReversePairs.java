package offl.leetcodes;

public class leet_ReversePairs {

       static class OrderStatisticTreeL {

            private static final boolean RED = true;
            private static final boolean BLACK = false;

            private class Node {
                long key;
                Node left, right, parent;
                boolean color = RED;
                long size = 1; // subtree size

                Node(long key) {
                    this.key = key;
                }
            }

            private Node root = null;

            private long size(Node n) {
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
            public void insert(long key) {
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
            public void erase(long key) {
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
                while (x != root && (x == null || x.color == BLACK)) {
                    Node p = x.parent;
                    if (x == p.left) {
                        Node w = p.right;
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
                        Node w = p.left;
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
            public long order_of_key(long key) {
                Node x = root;
                long result = 0;
                while (x != null) {
                    if (key <= x.key) x = x.left;
                    else {
                        result += 1 + size(x.left);
                        x = x.right;
                    }
                }
                return result;
            }

            public Long find_by_order(long k) {
                if (k < 0 || k >= size(root)) return null;
                Node x = root;
                while (x != null) {
                    long leftSize = size(x.left);
                    if (k < leftSize) x = x.left;
                    else if (k == leftSize) return x.key;
                    else {
                        k -= leftSize + 1;
                        x = x.right;
                    }
                }
                return null;
            }

            public boolean contains(long key) {
                Node x = root;
                while (x != null) {
                    if (key == x.key) return true;
                    if (key < x.key) x = x.left;
                    else x = x.right;
                }
                return false;
            }

            //added
            public long size(){
                return size(root);
            }
        }

        public static int reversePairs(int[] nums) {
            OrderStatisticTreeL ost = new OrderStatisticTreeL();

            int ans =0;

            for(int num: nums){

                 System.out.println("for "+num);

                long num2p1 = ((long)num)*2+1;

                 System.out.println("num2p1 = "+num2p1);

                long position = ost.order_of_key(num2p1);
                // if(position==null){
                //     System.out.println("returned null on "+num2p1);
                //     position=ost.size();
                // }

                int totalCnt = (int)(ost.size() - position);
                ans += totalCnt;
                 System.out.println("pos:"+position+" cnt:"+totalCnt);

                ost.insert(num);

                 for(int x=0; x<ost.size();x++){
                     System.out.print(ost.find_by_order(x)+" ");
                 }System.out.println();System.out.println();System.out.println();
            }

            return ans;
        }


    public static void main(String[] args){
        //int[] nums = {1,3,2,3,1}; //2
        int[] nums = {2,4,3,5,1}; //3

        int ans = reversePairs(nums);
        System.out.println("ans:"+ans);
    }


}
