class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        vector<int> ans(nums.size());
        int i = nums.size()-1;
        while(i >= 0){

            int x = nums[s] * nums[s];
            int y = nums[e] * nums[e];

            if(x > y){
                ans[i] = x;
                i--;
                s++;
            }
            else{
                ans[i] = y;
                i--;
                e--;
            }
            
        }

        return ans;
    }
};
