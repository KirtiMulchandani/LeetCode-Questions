class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        list<int> v;
        vector<int> ans;
        int i = 0, j = 0;

        while(j  < nums.size()){
            
            //calculation part
            while(v.size() > 0 && v.back() < nums[j]){
                v.pop_back();
            }

            v.push_back(nums[j]);


            // when the window size hasn't been got hit
            if(j - i + 1 < k)
                j++;

            // when the window size got hit
            else if(j - i + 1 == k){  

                // do 2 things

                //1. get the answer
                ans.push_back(v.front());

                //2. slide the window
                if(v.front() == nums[i]){
                    v.pop_front();
                }

                i++;
                j++;

            }

        }

        return ans;
    }
};
