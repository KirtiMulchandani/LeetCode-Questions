class Solution {
    void flip(vector<int>& arr, int s, int e){

        while(s < e){
            swap(arr[s++], arr[e--]);
        }
    }
  
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;

        for(int i = arr.size()-1; i > 0; i--){

            for(int j = 1; j <= i; j++){

                if(arr[j] == i+1){
                    flip(arr, 0, j);
                    ans.push_back(j+1);
                    break;
                }
            }

            flip(arr, 0, i);
            ans.push_back(i+1);
        }

        return ans;
    }
};
