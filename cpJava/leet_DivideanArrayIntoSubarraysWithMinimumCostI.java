class Solution {
    public int minimumCost(int[] nums) {
        int a=nums[1],b=nums[2];
        if(a>b){
            a+=b;
            b=a-b;
            a-=b;
        }

        for(int i=3; i<nums.length; i++){
            if(nums[i] < b){
                if(nums[i] < a){
                    b=a;
                    a=nums[i];
                }else{
                    b=nums[i];
                }
            }
        }

        return nums[0]+a+b;
    }
}