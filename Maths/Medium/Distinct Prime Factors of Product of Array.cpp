class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {

        int n = 1001;
        vector<bool> prime(n, 1); // for marking number as prime(1) or non-prime(0)
        vector<int> hp(n, 0); // for finding highest prime of a prticular number
        prime[0] = prime[1] = 0;

        for(int i = 2; i < n; i++){
            if(prime[i]){
                hp[i] = i; // the highest prime of any prime number is that number itself.

                for(int j = 2*i; j < n; j += i){
                    prime[j] = 0;
                    hp[j] = i; 
                }

            }
        }

        unordered_map<int ,int> m;

        for(int i = 0; i < nums.size(); i++){
            int t = nums[i];

            while(t > 1){
                int prime_factor = hp[t];
                while(t % prime_factor == 0){
                    t /= prime_factor;
                    m[prime_factor]++;
                }

            }
        }
        
        return m.size();
    }
};
