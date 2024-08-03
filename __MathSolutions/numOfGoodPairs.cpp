class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        /*
        // time: O(n^2), space: O(1)
        for(int i= 0; i<nums.size()-1; i++){
            for(int j=i+1; j< nums.size(); j++){
                if(nums[i]==nums[j]) res++;
            }
        }
        return res; */
      // time O(n), space O(n)
        unordered_map<int, int> hash; 
        for(int i = 0; i<nums.size(); i++) hash[nums[i]]++;
        for(auto n : hash) res += n.second *(n.second-1)/2;
        return res; 
    }
};
