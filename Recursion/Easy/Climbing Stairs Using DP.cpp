class Solution {
public:

    int solve(int n, vector<int> &dp){

        if(n == 1)
            return 1;
        
        else if(n == 2)
            return 2;
        
        else if(dp[n-1] != -1)
            return dp[n-1];

        return dp[n-1] = solve(n-1, dp) + solve(n-2, dp); 
    }

    int climbStairs(int n) {

        vector<int> dp(n, -1);
        return solve(n, dp);

    }
};
