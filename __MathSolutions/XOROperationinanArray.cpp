class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i=start;i<=start+2*(n-1);i=i+2){
            res = res^i;
        }
        return res;
    }
};
