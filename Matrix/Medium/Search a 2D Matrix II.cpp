class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

        int i = 0, j = col-1; // put the pointer at the top right or at the bottom left corner of the matrix and start traversing from top to bottom or bottom to top depending upon where the pointer is at.

        while(i < row && j >= 0){
            if(matrix[i][j] == target)  // if the element is equal to target element, return true
                return true;
            
            else if(matrix[i][j] > target) // otherwise check if it is lesser, then move in left direction
                j--;
            
            else //otherwise move in bottom direction
                i++;
        }

        return false;

    }
};







/* 
TC: O(m+n) 
SC: O(1)
*/
