//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        
        int i = 0, j = 0;
        long maxSum = INT_MIN, sum = 0;
        
        for(i = 0; i < K; i++){
            sum += Arr[i];
        }
        
        maxSum = max(sum, maxSum);
        
        while(i < N){
            sum += Arr[i];
            sum -= Arr[j];
            i++, j++;
            
            maxSum = max(sum, maxSum);
        }
        
        return maxSum;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
