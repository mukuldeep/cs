class Solution {

    TreeMap<Integer, Integer> low = new TreeMap<>();
    TreeMap<Integer, Integer> high = new TreeMap<>();

    long sumLow = 0;
    int lowCount = 0;
    int need;

    void add(TreeMap<Integer,Integer> map, int v) {
        map.put(v, map.getOrDefault(v, 0) + 1);
    }

    void remove(TreeMap<Integer,Integer> map, int v) {
        int c = map.get(v);
        if (c == 1) map.remove(v);
        else map.put(v, c - 1);
    }

    void addNum(int v) {
        if (lowCount < need) {
            add(low, v);
            sumLow += v;
            lowCount++;
        } else if (!low.isEmpty() && v <= low.lastKey()) {
            add(low, v);
            sumLow += v;
            lowCount++;

            int move = low.lastKey();
            remove(low, move);
            sumLow -= move;
            lowCount--;

            add(high, move);
        } else {
            add(high, v);
        }
    }

    void removeNum(int v) {
        if (low.containsKey(v)) {
            remove(low, v);
            sumLow -= v;
            lowCount--;

            if (!high.isEmpty()) {
                int move = high.firstKey();
                remove(high, move);
                add(low, move);
                sumLow += move;
                lowCount++;
            }
        } else {
            remove(high, v);
        }
    }

    public long minimumCost(int[] nums, int k, int dist) {
        if (k == 1) return nums[0];

        need = k - 1;
        int w = dist + 1;

        long ans = Long.MAX_VALUE;

        for (int i = 1; i <= w && i < nums.length; i++) {
            addNum(nums[i]);
        }
        ans = sumLow;

        for (int i = w + 1; i < nums.length; i++) {
            removeNum(nums[i - w]);
            addNum(nums[i]);
            ans = Math.min(ans, sumLow);
        }

        return nums[0] + ans;
    }
}