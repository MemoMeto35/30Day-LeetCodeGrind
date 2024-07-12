// Time Complexity O(N^2)
// Space Complexity O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        for(int i = 0; i< height.size(); i++){
            for(int j = i+1; j < height.size(); j++){
                int width = j-i; 

                int length = min(height[i], height[j]);
                
                int area = width*length;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
