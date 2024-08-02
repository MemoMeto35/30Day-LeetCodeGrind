class Solution {
public:
    string getPermutation(int n, int k) {
    int factorial = 1;
    for(int i = 1; i<=n; i++) factorial *= i;
    if(k == factorial){
        string lol = "";
        for(int i = n; i>=1; i--) lol.push_back(i+'0');
        return lol;
    }

    vector<int> nums;
    for(int i = 1; i<=n; i++) nums.push_back(i);
    string res = "";

    int s = 0;
    k = k-1;
    while(k || s){
        int i = n--;
        int mins = 1;
        while(--i)  mins *= i;
        s = k/mins;
        k -= s*mins;
        res.push_back(nums[s]+'0');
        nums.erase(nums.begin()+s);
    }
    for(int i = 0; i<nums.size(); i++){
        res.push_back(nums[i]+'0');
    }
    return res; 
    }

};
