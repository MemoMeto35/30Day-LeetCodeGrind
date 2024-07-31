class Solution {
public:
    
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> arr;
        arr.push_back(1);
        arr.push_back(1);
        for(int i = 2; i<= n; i++){
            arr.push_back(arr[i-1]+arr[i-2]);
        }
        return arr[n];
        
    }
};
