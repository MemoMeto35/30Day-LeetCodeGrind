class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        if(nums.size() <=4 && nums[0]+nums[1]+nums[2]==0) return {{nums[0], nums[1], nums[2]}}; // just to get the code faster
        

        for(int i = 0; i<nums.size(); i++){
            int j = i+1, k= nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) {j++;}
                    
                    while(j<k && nums[k]==nums[k+1]) {k--;}

                }
                else if(nums[i]+nums[j]+nums[k]<=0){
                    j++;
                    while(j<k && nums[j] == nums[j-1]) {j++;}
                    
                }
                else{
                    k--;
                    while(j<k && nums[k]==nums[k+1]) {k--;}

                }
            }
            
        }
        return res;
        
    }
};
