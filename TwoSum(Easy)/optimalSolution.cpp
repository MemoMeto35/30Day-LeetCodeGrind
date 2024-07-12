class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map <int, int> hash;
      for(int i = 0; i<nums.size(); i++){
        int numToFind = target - nums[i];
        if(hash.find(numToFind) != hash.end()){
          return {hash[numToFind], i};
        }
        else{
          hash[nums[i]] = i;
        }
        
      }
      return {};

    }
};
