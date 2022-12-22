class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int m = s + (e-s)/2;

        while(s <= e){

            m = s + (e-s)/2;

            if(nums[m] == target)  // check whether element at mid is eual to target or not
                return m;
            
            // decide where to go either in left part or in right part
            // for that, check if left part is sorted i.e., nums[m] > nums[s] 
            if(nums[m] >= nums[s]){
                // now check whether the target lies in the range
                if(nums[s] <= target && target <= nums[m])
                    e = m-1;
                else
                    s = m+1;
            }
            // check if right part is sorted
            else{
                if(nums[m] <= target && target <= nums[e])
                    s = m+1;
                else
                    e = m-1;
            }

        }

        return -1;
    }
};
