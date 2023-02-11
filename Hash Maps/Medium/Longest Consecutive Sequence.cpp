class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int cnt = 0;
        
        for(auto i : s){
            if(s.find(i-1) != s.end())
                continue;
            
            else{
                int curr = i;
                int c = 0;
                while(s.find(curr) != s.end()){
                    c++;
                    curr++;
                }

                cnt = max(c, cnt);
            }
        }
        return cnt;
    }
};
