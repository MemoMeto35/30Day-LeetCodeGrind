// Key Opservations
// the middle element is 5; 
// the bordering elements follow the 2,9,4,3,8,1,6,7 sequence, starting at some corner element and going either clockwise or counter-clockwise.
// corner elements are even, middle elements are odd; 
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // The sequences are each repeated twice to account for
        // the different possible starting points of the sequence
        // in the magic square
        string sequence = "2943816729438167";
        string sequenceReversed = "7618349276183492";

        string border = "";
        // Flattened indices for bordering elements of 3x3 grid
        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border += to_string(num);
        }

        // Make sure the sequence starts at one of the corners
        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
                (sequence.find(border) != string::npos ||
                 sequenceReversed.find(border) != string::npos));
    }
};

// My brute Force Solution
class Solution {
public:
    void findMagicSquares(vector<vector<int>>& grid, int &ans, int row, int col){
        if(row+2>=grid.size()||col+2>=grid[0].size()) return;
        if(grid[row+1][col+1]!=5) return; 
        int r1 = 0, r2 = 0, r3 = 0, c1 = 0, c2 = 0, c3 = 0, d1 = 0;
        unordered_map<int, int> hash; 
        for(int i = 1; i<=9; i++){
            hash[i]+=2;
        }
        for(int i = col; i<=col+2; i++){
            r1+=grid[row][i];
            if(hash.find(grid[row][i])==hash.end() || hash[grid[row][i]]==0) return; 
            hash[grid[row][i]]--;
        }
        if(r1!=15) return;
        for(int i = col; i<=col+2; i++){
            r2+=grid[row+1][i];
            if(hash.find(grid[row+1][i])==hash.end() || hash[grid[row+1][i]]==0) return; 
            hash[grid[row+1][i]]--;
        }
        if(r2!=15) return;
        for(int i = col; i<=col+2; i++){
            r3+=grid[row+2][i];
            if(hash.find(grid[row+2][i])==hash.end() || hash[grid[row+2][i]]==0) return; 
            hash[grid[row+2][i]]--;
        }
        if(r3!=15) return;

        for(int i = row; i<=row+2; i++){
            c1+=grid[i][col];
            if(hash.find(grid[i][col])==hash.end() || hash[grid[i][col]]==0) return; 
            hash[grid[i][col]]--;
        }
        if(c1!=15) return;
        for(int i = row; i<=row+2; i++){
            c2+=grid[i][col+1];
            if(hash.find(grid[i][col+1])==hash.end() || hash[grid[i][col+1]]==0) return; 
            hash[grid[i][col+1]]--;
        }
        if(c2!=15) return;
        for(int i = row; i<=row+2; i++){
            c3+=grid[i][col+2];
            if(hash.find(grid[i][col+2])==hash.end() || hash[grid[i][col+2]]==0) return; 
            hash[grid[i][col+2]]--;
        }
        if(c3!=15) return;
        int j = col; 
        for(int i = row; i<=row+2; i++){
            d1+=grid[i][j++];
        }
        if(d1!=15) return;

        ans++;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 ||grid[0].size()<3) return 0;
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                findMagicSquares(grid, ans, i, j);
            }
        }
        return ans; 

    }
};

// editorial Manual scan solution
// Time: O(m*n), space: O(1)
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        bool seen[10] = {false};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9) return false;
                if (seen[num]) return false;
                seen[num] = true;
            }
        }

        // Check if diagonal sums are the same
        int diagonal1 =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2 =
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

        if (diagonal1 != diagonal2) return false;

        // Check if all row sums are the same as the diagonal sums
        int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
                   grid[row + 1][col + 2];
        int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
                   grid[row + 2][col + 2];

        if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1)) {
            return false;
        }

        // Check if all column sums are the same as the diagonal sums
        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
                   grid[row + 2][col + 1];
        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
                   grid[row + 2][col + 2];

        if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1)) {
            return false;
        }

        return true;
    }
};
