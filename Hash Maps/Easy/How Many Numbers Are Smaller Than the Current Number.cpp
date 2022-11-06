class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < nums.size(); i++){
            if(m.find(temp[i]) == m.end())  // if the value isn't present
                m[temp[i]] = i;
        }
        
        // mapping
        for(int i = 0; i < nums.size(); i++){
            nums[i] = m[nums[i]];
        }
        
        return nums;
    }
};
