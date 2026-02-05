class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back( nums[(abs(nums[i])*n+i+nums[i])%n] );
        }

        return res;
    }
};