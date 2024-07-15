class Solution {
public:
    int trap(vector<int>& height) {
        int totalWaterTrapped= 0; 
        for(int i = 0; i < height.size(); i++){
            int left = i, right = i;
            int maxLeft = 0, maxRight = 0;
            while(left>=0){
                maxLeft = max(maxLeft, height[left]);
                left--;

            }
            while(right< height.size()){
                maxRight = max(maxRight, height[right]);
                right++;

            }
            int currentWater = min(maxRight, maxLeft) - height[i];
            if(currentWater>0) totalWaterTrapped+=currentWater;

        }
        return totalWaterTrapped; 
    }
};
