class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int i : nums){
            int x1 = i - k;
            int x2 = i + k;

            if(m[x1])
                ans += m[x1];
            if(m[x2])
                ans += m[x2];

            m[i]++;

        }

        return ans;
    }
};
