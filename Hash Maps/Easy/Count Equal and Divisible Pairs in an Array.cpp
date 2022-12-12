class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m; // for storing the indices of same element into a vector i.e. mapping a single elements to different indices for further occurrence
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                vector<int> v = m[nums[i]];

                //iterating through different indices
                for(int j : v){
                    if(i * j % k == 0)
                    ans++;
                }
            }
            //for storing further occurrence
            m[nums[i]].push_back(i);
        }

        return ans;
    }
};
