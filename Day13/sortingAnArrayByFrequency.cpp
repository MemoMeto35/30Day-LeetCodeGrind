/*
The lambda [&](int a, int b) { ... } serves as the comparator for the sort function:

& captures all external variables (freq in this case) by reference, allowing the lambda to access and use freq.
(int a, int b) defines parameters for elements to compare.
Comparison logic:
If frequencies are equal (hash[a] == hash[b]), sort by value in descending order (a > b).
Otherwise, sort by frequency in ascending order (hash[a] < hash[b]).

*/
class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> hash; 
        for(int i =0; i< nums.size(); i++){
            hash[nums[i]]++;
        }
        
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return hash[a]!=hash[b] ? hash[a]<hash[b] : a>b;
        });
        return nums;
    }
};

