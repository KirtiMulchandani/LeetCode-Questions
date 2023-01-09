class Solution {
    void insert(vector<int>& arr, int i, int j){
        if(j < arr.size())
            arr[j] = arr[i];
    }
    
    void print(vector<int>& arr){
        for(int i : arr)
            cout << i << " ";
        cout << endl;
    }

public:
    void duplicateZeros(vector<int>& arr) {

        int zeros = 0;

        for(int i : arr)
            if(i == 0)   
                zeros++;

        
        int i = arr.size()-1, j = arr.size() + zeros - 1;

        while(i != j){

            insert(arr, i, j--);
            if(arr[i] == 0)
                insert(arr, i, j--);
            
            i--;

            print(arr);

        }

    }
};
