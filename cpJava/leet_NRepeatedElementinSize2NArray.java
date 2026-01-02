class Solution {
    public int repeatedNTimes(int[] nums) {

        HashSet<Integer> st = new HashSet<>();
        
        for(int x: nums){
            if(st.contains(x)){
                return x;
            }
            st.add(x);
        }

        return 0;
    }
}