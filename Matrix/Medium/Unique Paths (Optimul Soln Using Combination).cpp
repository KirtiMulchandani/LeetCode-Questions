class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N = m + n - 2; // number of the directions in which we can move
        int r = m-1; // to determine the step required to move in right or in bottom
        double ans = 1; // final answer will be NCr

        for(int i = 1; i <= r; i++){
            ans = ans * (N - r + i) / i;
        }
        
        return (int)ans;
    }
};
