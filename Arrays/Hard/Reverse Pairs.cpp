class Solution {
public:
    int merge(vector<int>& nums, int s, int m, int e){

        int cnt = 0;

        int j = m+1, i = s;

        for(i = s; i <= m; i++){
            long long n = nums[j];
            while(j <= e && nums[i] > 2 * n){
                j++;
                n = nums[j];
            }
            cnt += (j - (m+1));
        }

        vector<int> temp;
        i = s, j = m+1;

        while(i <= m && j <= e){
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while(i <= m){
            temp.push_back(nums[i++]);
        }
        
        while(j <= e){
            temp.push_back(nums[j++]);
        }

        for(int k = s; k <= e; k++){
            nums[k] = temp[k-s];
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int s, int e){
        if(s >= e)
            return 0;

        int m = s + (e-s)/2;    

        int cnt = mergeSort(nums, s, m);
        cnt += mergeSort(nums, m+1, e);
        cnt += merge(nums, s, m, e);
        return cnt;
        
    }
    int reversePairs(vector<int>& nums) {
        
       return mergeSort(nums, 0, nums.size()-1);

    }
};
