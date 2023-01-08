class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();
        int firstPosInd = lower_bound(nums.begin(), nums.end(), 1) -  nums.begin();
        int firstZeroInd = lower_bound(nums.begin(), nums.end(), 0) -  nums.begin();
        
        int numberOfZeros = firstPosInd - firstZeroInd;
        return max(firstPosInd - numberOfZeros, n - firstPosInd);
    }
};




/*
Intuition
find total number of zeros and first index of any positive number
totalNumberOfZeros = firstPosIndex - firstZeroIndex
totalNumberOfNegNums = firstPosIndex - totalNumberOfZeros
totalNumberOfPosNums = n - firstPosIndex
*/
