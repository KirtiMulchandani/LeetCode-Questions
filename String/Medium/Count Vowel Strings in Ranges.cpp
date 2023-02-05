class Solution {
public:

    bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> ans(queries.size());
        vector<int> temp(words.size()+1);
        
        // precomputation
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            if(vowel(s[0]) && vowel(s[s.length()-1]))
                temp[i+1] = temp[i]+1;
            else
                temp[i+1] = temp[i];
        }

        for(int i = 0; i < queries.size(); i++){

            int l = queries[i][0];
            int r = queries[i][1];
            int cnt = temp[r+1] - temp[l];
            ans[i] = cnt;

        }

        return ans;

    }
};
