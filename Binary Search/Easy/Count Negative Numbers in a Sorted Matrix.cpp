class Solution {
public:

    int binarySearch(vector<int> a){
        int s = 0, e = a.size() - 1;
        int m = s + (e - s)/2;

        while(s <= e){
            if(a[m] < 0)
                e = m-1;
            else
                s = m+1;
            m = s + (e - s)/2;
        }

        int count = a.size() - s;
        return count;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto i : grid){
            ans += binarySearch(i);
        }

        return ans;
    }
};
