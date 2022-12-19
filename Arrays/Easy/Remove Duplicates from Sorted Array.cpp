class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]) //if element at i and j are not same, then increment i and place jth element at ith index 
                i++;
            nums[i] = nums[j]; //if they are same, then move j
        }
        return i+1;
    }
};
