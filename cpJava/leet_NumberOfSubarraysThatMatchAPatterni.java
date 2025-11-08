package offl.leetcodes;

public class leet_NumberOfSubarraysThatMatchAPatterni {

    public static int countMatchingSubarrays(int[] nums, int[] pattern) {
        int ans = 0;

        for(int i = 0; i<nums.length - pattern.length; i++){
            boolean isMatch = true;
            for(int j=0; j < pattern.length; j++){
                switch (pattern[j]){
                    case -1:
                        isMatch = (nums[i+j] > nums[i+j+1]);
                        break;
                    case 0:
                        isMatch = (nums[i+j] == nums[i+j+1]);
                        break;
                    case 1:
                        isMatch = (nums[i+j] < nums[i+j+1]);
                        break;
                }
                if(!isMatch){
                    break;
                }
            }
            if(isMatch){
                ans++;
            }

        }

        return ans;
    }

    public static void main(String[] args){
        int[] nums = {1,2,3,4,5,6};
        int[] patt = {1,1};
        //int[] nums = {3,2,4,2};


        int ans = countMatchingSubarrays(nums,patt);
        System.out.println(ans+" ");

    }
}
