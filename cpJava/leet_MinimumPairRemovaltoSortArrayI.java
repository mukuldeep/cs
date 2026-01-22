class Solution {

    private boolean isNonDecreasing(java.util.ArrayList<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i) < arr.get(i - 1)) {
                return false;
            }
        }
        return true;
    }

    public int minimumPairRemoval(int[] nums) {
        int operations = 0;
        java.util.ArrayList<Integer> arr = new java.util.ArrayList<>();
        for (int x : nums) arr.add(x);

        while (!isNonDecreasing(arr)) {

            int minSum = Integer.MAX_VALUE;
            int idx = -1;

            for (int i = 0; i < arr.size() - 1; i++) {
                int sum = arr.get(i) + arr.get(i + 1);
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            int merged = arr.get(idx) + arr.get(idx + 1);
            arr.set(idx, merged);
            arr.remove(idx + 1);

            operations++;
        }
        return operations;
    }
}