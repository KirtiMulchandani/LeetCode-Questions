class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> m;
        int i = 0, j = 0, mn = INT_MAX;
        string ans;

        for(char i :  t)
            m[i]++;
        
        int cnt = m.size();
        
        while(j < s.length()){

            // see whether the char at j exist in the map already
            if(m.find(s[j]) != m.end()) // if it is, then decrement its count
            {
                m[s[j]]--;

                if(m[s[j]] == 0) // if the character's count becomes 0 then also decrement cnt by 1
                    cnt--;
            }

            if(cnt > 0)
                j++;
            
            else if(cnt == 0){ // when our requirement got fullfilled
                if(j - i + 1 < mn){
                    mn = j - i + 1;
                    ans = s.substr(i, mn);
                }

                while(cnt == 0 && i <= j){  // minimize the ans string
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        
                        if(m[s[i]] == 1){
                            if(j - i + 1 < mn){
                                mn = j - i + 1;
                                ans = s.substr(i, mn);
                            }
                            cnt++;
                        }

                    }

                    i++;
                }
                
                j++;

            }

        }

        return ans;
    }
};
