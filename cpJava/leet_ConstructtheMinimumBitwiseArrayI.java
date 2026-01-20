class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int[] pc = new int[1_005];
        Arrays.fill(pc, -1);
        for(int i=0; i<=2_048;i++){
            int x = i|(1+i);
            if(x<=1000 && pc[x] == -1){
                pc[x] = i;
            }
        } 

        int[] ans = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            ans[i] = pc[nums.get(i)];
        }

        return ans;
    }
}