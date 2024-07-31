class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10001]{0};
        int val[10001]{0};
        for(auto i : nums){
            val[i] += i; 
        }
        int mx = *max_element(nums.begin(), nums.end());
        dp[1] = val[1];
        for(int i = 2; i<=mx; i++){
            dp[i] = max(dp[i-1], dp[i-2]+val[i]);
        }
        return dp[mx];
    }
};
