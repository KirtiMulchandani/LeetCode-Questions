class Solution {
public:
    int countPrimes(int n) {

        vector<bool> prime(n+1, 1);  //mark every number as prime
        prime[0] = prime[1] = 0; // except 0 and 1
        int count = 0;

        for(int i = 2; i < n; i++){
            if(prime[i]){ // if element's entry is true, that means, it is found to be prime so far. So, we increment the count and mark it's all multiples as non-prime.
                count++;
            
                for(int j = 2 * i; j < n; j += i){
                    prime[j] = 0;
                }
            }

        }

        return count;
    }
};
