package offl.leetcodes;

import java.util.*;
import java.util.stream.IntStream;

public class countOfSmallerNumbersAfterSelf {


    static class FenwickTree {
        int[] bit;
        int n;

        FenwickTree(int n) {
            this.n = n + 2; // 1-based indexing
            bit = new int[this.n];
        }

        // add value to index i
        void update(int i, int val) {
            while (i < n) {
                bit[i] += val;
                i += (i & -i);
            }
        }

        // sum of values from 1..i
        int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= (i & -i);
            }
            return sum;
        }
    }

    public static List<Integer> countSmaller(int[] nums) {
        ArrayList<Integer> ans = new ArrayList<>();

        // --- Step 1: Coordinate compression ---
        int[] num_r = IntStream.range(0, nums.length)
                .map(i -> nums[nums.length - i - 1])
                .toArray();

        int[] sorted = num_r.clone();

        Arrays.sort(sorted);

        Map<Integer, Integer> rank = new HashMap<>();
        int id = 1;
        for (int x : sorted)
            if (!rank.containsKey(x))
                rank.put(x, id++);

        // --- Step 2: Fenwick tree ---
        FenwickTree ft = new FenwickTree(rank.size());

        // --- Step 3: Insert elements one by one ---
        for (int x : num_r) {
            int idx = rank.get(x);
            int smaller = ft.query(idx - 1); // count of smaller elements
            System.out.println("Adding " + x + " → smaller elements: " + smaller);
            ans.add(smaller);
            ft.update(idx, 1);
        }


        Collections.reverse(ans);
        return ans;
    }


    public static void main(String[] args){
        int[] nums = {1, 2, 3, 4, 7, 2, 6, 10, 13, 7, 23, 8};
        //ArrayList<Integer> list = new ArrayList<>();

        List<Integer> ans = countSmaller(nums);

        System.out.println();
        for (Integer el:ans) {
            System.out.print(el+", ");
        }
        System.out.println();





    }
}
