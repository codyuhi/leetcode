class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int * dp = new int[nums.size()]();
        dp[0] = nums[0];
        int ls = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            ls = max(ls, dp[i]);
        }
        return ls;
    }
};