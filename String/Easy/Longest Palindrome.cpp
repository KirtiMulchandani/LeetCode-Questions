class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int ans = 0, oddCount = 0;

        for(char ch : s){
            m[ch]++;
            if(m[ch] % 2 == 1)
                oddCount++;
            else
                oddCount--;
        }

        if(oddCount > 1)
            return s.length() - oddCount + 1;
        else
            return s.length();
    }
};
