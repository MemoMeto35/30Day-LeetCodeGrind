class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1[0] == '0' || nums2[0] == '0') return "0";
        const int n = nums1.size();
        const int m = nums2.size();
        vector<int> res(m+n,0);
        for(int i = m-1; i>=0; i--){
            int digit1 = nums2[i] - '0';
            for(int j = n-1; j>=0;j--){
                int digit2 = nums1[j]-'0';
                int sum = digit1 * digit2 + res[i+j+1]; 
                res[i+j+1] = sum%10;
                res[i+j] += sum/10;
            }
        }
        string s = "";
        for(auto num:res){
            if(!(s.empty() && num==0)){s.push_back(num+'0');}
        }
        return s; 

    }
};
