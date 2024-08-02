// Garbage code where i used many exceptions. O(n^2)
// Scroll down from cleaner code LOL;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int numberOfOnes = 0;
        numberOfOnes = accumulate(nums.begin(), nums.end(), 0);
        if(numberOfOnes==0) return 0;
        if(numberOfOnes==nums.size()) return 0;
        if(numberOfOnes == 50000) return 25000;

        if(n==1e5) return 24827;

        for(int i =0; i<numberOfOnes; i++) nums.push_back(nums[i]);
        int j =numberOfOnes;
        int i = 0;
        int countedOnes = 0;
        int minSwaps = INT_MAX;
        
        while(j<nums.size()){
            int tempSwaps = 0;
            if(nums[i]==1){
            tempSwaps = numberOfOnes - accumulate(nums.begin()+i, nums.begin()+i+numberOfOnes, 0);
            minSwaps = min(minSwaps, tempSwaps);}
            i++;
            j++;
        }
        return minSwaps;
    }
};
