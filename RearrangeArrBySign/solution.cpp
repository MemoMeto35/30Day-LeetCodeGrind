class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int posInd = 0;
        int negInd = 1;
        for(int i =0; i<n; i++){
            if(nums[i]>0){
                res[posInd] = nums[i];
                posInd+=2;
            }
            else{
                res[negInd] = nums[i];
                negInd+=2;
            }

        }
        return res; 

    }
};
