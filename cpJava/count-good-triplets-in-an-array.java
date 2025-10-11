class Solution {

    static class Fenwick {
        int[] bit;
        int n;
        Fenwick(int n) {
            this.n = n;
            bit = new int[n + 1];
        }
        void update(int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }
        int query(int idx) {
            int sum = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                sum += bit[idx];
            return sum;
        }
    }

    public long goodTriplets(int[] nums1, int[] nums2) {

        long ans = 0;

        Map<Integer, Integer> el2Index = new HashMap<>();

        for(int i=0;i<nums1.length;i++){
            el2Index.put(nums1[i],i);
        }

        //replace in nums2
        int[] nums = new int[nums2.length];
        for(int i=0;i<nums2.length;i++){
            nums[i]=el2Index.get(nums2[i]);
        }

        //find
        Fenwick fenwick = new Fenwick(nums.length);

        for (int i = 0; i < nums.length; i++) {
            int smallers_n = (nums[i] == 0) ? 0 : fenwick.query(nums[i] - 1);
            fenwick.update(nums[i], 1);
            int larger_n_post = (nums.length + smallers_n - nums[i] - i  - 1 );
            ans+= (long) smallers_n * (long) larger_n_post;
        }
        
        return ans;
    }

}