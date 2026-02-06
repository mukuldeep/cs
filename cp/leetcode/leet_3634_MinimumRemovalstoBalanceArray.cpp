class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int removalN = nums.size()-1;

        for(int i=0;i<nums.size();i++){
            auto it = upper_bound(nums.begin(), nums.end(), ((long)nums[i]*k));
            removalN = min(removalN, (int)(nums.size()  - (it - nums.begin()-i))); 
        }

        return removalN;
    }
};