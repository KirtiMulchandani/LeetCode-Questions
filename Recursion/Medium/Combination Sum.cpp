class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> output, int index, int target){
       if(index == nums.size()){
           if(target == 0)
                ans.push_back(output);
           return;
       } 
        
        if(nums[index] <= target){        
            int element = nums[index];
            output.push_back(element);
            solve(nums, ans, output, index, target-nums[index]);    
            output.pop_back();      
        }

        solve(nums, ans, output, index+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, ans, output, 0, target);
        return ans;        
    }
};
