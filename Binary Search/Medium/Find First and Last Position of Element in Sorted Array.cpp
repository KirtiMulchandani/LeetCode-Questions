class Solution {
public:

    int leftPosition(vector<int> nums, int target){
        int s = 0, e = nums.size()-1;
        int m = s + (e-s)/2;
        int ans = -1;
        while(s <= e){
            if(nums[m] == target){
                ans = m;
                e = m-1;
            }
            else if(nums[m] > target)
                e = m-1;
            else
                s = m+1;
            
            m = s + (e-s)/2;
        }

        return ans;

    }

    int rightPosition(vector<int> nums, int target){
        int s = 0, e = nums.size()-1;
        int m = s + (e-s)/2;
        int ans = -1; 
        while(s <= e){
            if(nums[m] == target){
                ans = m;
                s = m+1;
            }
            else if(nums[m] < target)
                s = m+1;
                
            else
                e = m-1;
            
            m = s + (e-s)/2;
        }

        return ans;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftPosition(nums, target), right = rightPosition(nums, target);
        return {left, right};
        

    }
};
