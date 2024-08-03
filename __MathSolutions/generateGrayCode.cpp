// time: O(2^n)
class Solution {
public:
    vector<int> res;
    void generateSubGrayCode(int &num, int n){
        num ^= 1<<n; 
        res.push_back(num);
        for(int i = 0; i<n; i++){
            generateSubGrayCode(num, i);
        }
    }
    vector<int> grayCode(int n) {
        int num = 0; 
        res.push_back(num);
        for(int i= 0; i < n; i++){
            generateSubGrayCode(num, i);
        }
        return res;
    }
};
