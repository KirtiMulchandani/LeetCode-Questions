class Solution {
public:
    string sortString(string s) {

        unordered_map<char, int> m;
        string ans = "";

        int flag = 1;
        
        for(int i = 0; i < s.length(); i++) m[s[i]]++;

        while(flag){

            flag = 0;

            for(char i = 'a'; i <= 'z'; i++){
                if(m[i]){
                    ans += i;
                    m[i]--;
                    flag = 1;
                }
            }

            for(char i = 'z'; i >= 'a'; i--){
                if(m[i]){
                    ans += i;
                    m[i]--;
                    flag = 1;
                }
            }

 
        }

        return ans;
    }
};
