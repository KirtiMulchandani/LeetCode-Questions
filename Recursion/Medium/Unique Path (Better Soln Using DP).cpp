class Solution {
public:

    int solve(int m, int n, int i, int j, vector<vector<int>> &dp){

        // base case whenever our row or col get out of the bound
        if(i >= m || j >= n)
            return 0;
        
        // or it reaches at the bottom right corner
        if(i == m-1 && j == n-1)
            return 1;
        
        // you can move in the two directions either in bottom or in right
        if(dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = solve(m, n, i+1, j, dp) + solve(m, n, i, j+1, dp);
    }
    
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, 0, 0, dp);

    }
};



/*
TC: O(m*n)
SC: (m*n)
*/
