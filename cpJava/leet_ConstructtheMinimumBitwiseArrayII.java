class Solution {

    public static int smallestX(int P){
        if(P==2)
            return -1;
        int m=0,temp=P;
        while((temp&1)==1){
            m++;
            temp>>=1;
        }
        return P-(1<<(m-1));
    }

    public int[] minBitwiseArray(List<Integer> nums) {
        int[] ans = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            ans[i] = smallestX(nums.get(i));
        }
        return ans;
    }
}