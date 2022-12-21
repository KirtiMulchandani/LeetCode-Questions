class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> m;
        int sum = 0, ans = 0;

        for(int i =0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k)  // if the sum is equal to K then, increment the count
                ans++;
            
            if(m.find(sum - k) != m.end())  //if (sum - k) is present in the map that means the subarray with the target sum is obtained. So, increment the count
                ans += m[sum-k];

            m[sum]++;
        }
        return ans;
    }
};
