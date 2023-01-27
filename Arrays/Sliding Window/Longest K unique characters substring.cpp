//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char, int> m;
        int i = 0, j = 0, mx = -1;
        
        while(j < s.length()){
            
            // calculation part
            m[s[j]]++;
            
            
            // when the condition doesn't get hold
            if(m.size() < k)
                j++;
                
            // when the condition gets true i.e., number of unique character == k  
            else if(m.size() == k){
                mx = max(mx, j-i+1);
                j++;
            }
            
            // when we have crossed the condition
            else if(m.size() > k){
                
                while(m.size() > k){
                    
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                    
                }
                j++;
            }
            
            
        }
        
        return mx;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
