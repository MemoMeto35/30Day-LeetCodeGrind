// U have m*n grid, figure out the number of ways you can go from the top left corner to the bottom left corner

class Solution {
// Mathematical Way
// time: O(n), space: O(1)
public:
    int uniquePathsUsingMath(int m, int n) {
        int N=n+m-2;
        int r=n-1;
        double res=1; // this have to be double to be able to divide correctly without rounding
        for(int i=1;i<=r;i++){ // Excutes (N Chooses r)
            res=res*(N-r+i)/i;
        }
    return int(res); // because the answer needs to be integer without any extra figures. 
    }

//Recursive Way: O(n*m), O(n*m)
    int uniquePathsUsingRec(int m, int n) {
        int a[][] = new int[m][n]; // creating a new matrix; 
        return dest(a,m,n,0,0);
    }

    static int dest(int a[][],int m, int n, int i, int j){
        if(i>=m || j>=n) // to stop calling the function
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(a[i][j]>0) 
            return a[i][j]; // to prevent overlapping, Memoization
        return a[i][j] = dest(a,m,n,i+1,j) + dest(a,m,n,i,j+1); // it can come from above to sideways
    }
// Tabulation Solution
  int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        dp[0][0] = 1;
        for(int i =1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
