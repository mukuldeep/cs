class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i=0,j=0;
        for(;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i++]);
            }else{
                nums.push_back(nums2[j++]);                
            }
        }
        for(;i<nums1.size();){
                nums.push_back(nums1[i++]);
        }
        for(;j<nums2.size();){
                nums.push_back(nums2[j++]);
        }
        double med;
        if(nums.size()&1){
            med=nums[nums.size()/2];
        }else{
            med=(double)(nums[nums.size()/2]+nums[(nums.size()/2)-1])/2.0;
        }
        return med;
    }
};

