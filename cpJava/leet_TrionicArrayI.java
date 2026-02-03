class Solution {
    public boolean isTrionic(int[] nums) {
        int i=1, cnt=0;
        while(i<nums.length && nums[i-1]<nums[i]){
            cnt++;
            i++;
        }
        if(i == nums.length || cnt==0 ){
            return false;
        }
        
        cnt=0;
        while(i<nums.length && nums[i-1]>nums[i]){
            cnt++;
            i++;
        }
        if(i == nums.length || cnt==0){
            return false;
        }


        while(i<nums.length && nums[i-1]<nums[i]){
            i++;
        }
        if(i == nums.length){
            return true;
        }
        return false;


        
    }
}