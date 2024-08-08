// 885. Spiral Matrix III
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> result; 

        int left = cStart, right = cStart+1, top = rStart, bottom = rStart+1;
        int n = rows*cols; 
        result.push_back({rStart, cStart});

        while(n>1){
            for(int i = left+1; i<=right; i++){
                if(top<0 || top >= rows || i <0 || i>=cols) continue;
                {result.push_back({top, i});
                n--;}
            }
            top--;
            for(int i = top+2; i<=bottom; i++){
                if(right<0 || right >= cols || i <0 || i>=rows) continue;
                {result.push_back({i, right});n--;}
            }
            right++;
            if(top<=bottom){
                for(int i = right-2; i>=left-1; i--){
                    if(bottom<0 || bottom >= rows || i <0 || i>=cols) continue;
                    { result.push_back({bottom, i}); n--;}
                }
            }
            bottom++;
            if(left<=right){
                for(int i = bottom-2; i>=top; i--){
                    if(left-1<0 || left-1 >= cols || i <0 || i>=rows) continue;
                    {result.push_back({i, left-1}); n--;}
                }
            }
            left--;
        } 
        return result;
    }
};
// Another Solution
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        // Store all possible directions in an array.
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> traversed;

        // Initial step size is 1, value of d represents the current direction.
        for (int step = 1, direction = 0; traversed.size() < rows * cols;) {
            // direction = 0 -> East, direction = 1 -> South
            // direction = 2 -> West, direction = 3 -> North
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                        cStart < cols) {
                        traversed.push_back({rStart, cStart});
                    }
                    // Make changes to the current position.
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }

                direction = (direction + 1) % 4;
            }
            ++step;
        }
        return traversed;
    }
};
