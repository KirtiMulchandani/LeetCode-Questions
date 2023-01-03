class Solution {
public:

    int gcd(int a, int b){
        if(b == 0)
            return a;

        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;

        for(int i : nums){
            mn = min(mn, i);
            mx = max(mx, i);
        }

        return gcd(mn, mx);
    }
};





/* Euclid Algorithm is used ver here to find out gcd using recursion, which states 
gcd(a, b) = gcd(b, a%b)
gcd(a, 0) = a
*/
