class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0, left=0, right= height.size() -1, maxRight =0, maxLeft = 0; 
        if(height.size()<=1) return 0;

        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]>maxLeft){
                    maxLeft = height[left];
                }else{
                    trappedWater+= maxLeft - height[left];
                }
                left++;
            }else{
                if(height[right]>maxRight){
                    maxRight = height[right];
                }else{trappedWater+= maxRight - height[right];}
                right--;
            }
        }
        return trappedWater;
    }
};
