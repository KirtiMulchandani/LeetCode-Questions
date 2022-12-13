int key;
bool comp(int a, int b){        
  if((a < key && b > key) || (a == key && b > key) || (a < key && b == key))
        return true;
    else
        return false;
}
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        key = pivot;
        stable_sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};
