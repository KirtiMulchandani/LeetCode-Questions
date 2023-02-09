class Solution {
public:

    int solve(int m, int n, int i, int j){

        // base case whenever our row or col get out of the bound
        if(i >= m || j >= n)
            return 0;
        
        // or it reaches at the bottom right corner
        if(i == m-1 && j == n-1)
            return 1;
        
        // you can move in the two directions either in bottom or in right
        return solve(m, n, i+1, j) + solve(m, n, i, j+1);
    }
    
    int uniquePaths(int m, int n) {
        return solve(m, n, 0, 0);
    }
};
