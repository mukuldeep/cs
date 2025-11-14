package offl.leetcodes;

public class leet_FruitsIntoBaskets_iii {


    static class SegmentTree {
        int n;
        long[] treeMax;

        SegmentTree(int[] arr) {
            n = arr.length;
            treeMax = new long[4 * n];
            build(arr, 1, 0, n - 1);
        }

        void build(int[] arr, int node, int l, int r) {
            if (l == r) {
                treeMax[node] = arr[l];
                return;
            }
            int mid = (l + r) / 2;
            build(arr, 2 * node, l, mid);
            build(arr, 2 * node + 1, mid + 1, r);
            pull(node);
        }

        void pull(int node) {
            treeMax[node] = Math.max(treeMax[2 * node], treeMax[2 * node + 1]);
        }

        //point update
        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                treeMax[node] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (idx <= mid) update(2 * node, l, mid, idx, val);
            else update(2 * node + 1, mid + 1, r, idx, val);
            pull(node);
        }

        long queryMax(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return Long.MIN_VALUE;
            if (ql <= l && r <= qr) return treeMax[node];
            int mid = (l + r) / 2;
            return Math.max(queryMax(2 * node, l, mid, ql, qr),
                    queryMax(2 * node + 1, mid + 1, r, ql, qr));
        }
    }

//    public class segment_tree_sum_min_max {
//        public static void main(String[] args) {
//            int[] arr = {1, 3, 2, 7, 9, 11};
//            SegmentTree st = new SegmentTree(arr);
//
//            System.out.println(st.querySum(1, 0, arr.length - 1, 1, 4));
//            System.out.println(st.queryMin(1, 0, arr.length - 1, 1, 4));
//            System.out.println(st.queryMax(1, 0, arr.length - 1, 1, 4));
//
//            st.update(1, 0, arr.length - 1, 2, 10);
//            System.out.println(st.querySum(1, 0, arr.length - 1, 0, 5));
//        }
//    }


    private static int firstGreaterThanValue(int l, int r, int val, SegmentTree st, int n){

        while(l<r) {
            int mid = (l + r) / 2;
            int mx = (int) st.queryMax(1, 0, n, l, mid);

            System.out.println(l+"-"+mid+"-"+r+" =>"+mx);

            if (mx < val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        System.out.println(" "+val+" <=  at "+l);
        return l;


    }


    public static int numOfUnplacedFruits(int[] fruits, int[] baskets) {

        SegmentTree st = new SegmentTree(baskets);

        int unplacedCnt = 0;
        for(int fruit: fruits){
            boolean isPlaced = false;
            int l = firstGreaterThanValue(0, baskets.length-1, fruit,st,baskets.length-1);
            if(l == baskets.length-1 && baskets[l] < fruit ){//not found
                unplacedCnt++;
            }else{//found

                baskets[l]=0;
                st.update(1,0,baskets.length-1,l,0);
            }


//            for(int i=0;i<baskets.length;i++){
//
//                if(!v[i] && baskets[i] >= fruit){
//                    isPlaced = true;
//                    v[i] = true;
//                    break;
//                }
//            }
//            if(!isPlaced){
//                unplacedCnt++;
//            }
        }

        return unplacedCnt;
    }

    public static void main(String[] args){
        //int[] fruits = {4,2,5}, baskets = {3,5,4};

        //int[] fruits = {3,6,1}, baskets = {6,4,7};
        //int[] fruits = {38,2}, baskets = {59,63};

        int[] fruits = {4,2}, baskets = {6,5};


        int ans = numOfUnplacedFruits(fruits,baskets);
        System.out.println("ans="+ans);

    }

//    public static void main(String[] args) {
//            int[] arr = {6,5}; //{8, 3, 2, 7, 9, 11};
//            SegmentTree st = new SegmentTree(arr);
//
//            //System.out.println(st.querySum(1, 0, arr.length - 1, 1, 4));
//            //System.out.println(st.queryMin(1, 0, arr.length - 1, 1, 4));
//            System.out.println(st.queryMax(1, 0, arr.length - 1, 0, 0));
//
//            st.update(1, 0, arr.length - 1, 2, 10);
//            //System.out.println(st.querySum(1, 0, arr.length - 1, 0, 5));
//
//    }

}
