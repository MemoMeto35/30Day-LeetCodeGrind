// O(N)
// O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0, right = height.size() -1; 

        while(left<right){
            int width = right - left; 
            int length = min(height[right], height[left]);
            int area = width * length;

            if(height[left] < height[right]){
                left++;
            }else {right--;}

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
