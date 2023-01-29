class Solution {
public:
    int numberOfSubstrings(string s) {

        unordered_map<char, int> m;
        int cnt = 0, i = 0 , j = 0, n = s.length()-1;

        while(j <= n){

            m[s[j]]++;

            while(m['a'] && m['b'] && m['c']){
                cnt += n - j + 1;
                m[s[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
        
    }
};
