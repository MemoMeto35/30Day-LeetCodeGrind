class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x; 
        int start = 1; 
        int end = x; 
        int mid;
        while(start <= end){
            mid = start + (end-start)/2;
            if(mid>x/mid) end = mid-1;
            else if(mid<x/mid) start = mid +1; 
            else return mid; 
        }
        return start-1; 
    }
};
