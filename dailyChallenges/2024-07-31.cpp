// Filling Bookcase Shelves
// Time: O(n^2)
// Space: O(n) // memoization; 
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int minHeight[n+1];
        minHeight[0] = 0; // if there is nothing the height = 0;
      // BottomUp approach; 
        for(int i = 1; i<=n; i++){
            int w = books[i-1][0], h = books[i-1][1]; // initialise w, h;
            minHeight[i] = minHeight[i-1] + h;  // max possible minHeight depending on the privious; 
            for(int j = i-1; j>0; j--){
                w += books[j-1][0]; // adding to the width; 
                if(w>shelfWidth) break; 
                h = max(h, books[j-1][1]); // Highest book on the shelf; 
                minHeight[i] = min(minHeight[i], minHeight[j-1]+h); // it loops through all possibilities; 
            }
        }
        return minHeight[n];
    }
};
