//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    unordered_map<char, int> m;
	    
	    for(char i : pat)
	        m[i]++;
	        
	   int count = m.size(), k = pat.length(), ans = 0, i = 0, j = 0;
	   
	   while(j < txt.length()){
	       
	       // calculation part
	       if(m.find(txt[j]) != m.end()){
	            m[txt[j]]--;
	            
	            if(m[txt[j]] == 0)
	                count--;     
	       }
	       
	       // when window hasn't been got hit
	       if(j-i+1 < k)
	            j++;
	            
	       // when the window size is achieved
	       else if(j-i+1 == k){
	           
	           if(count == 0)
	                ans++;
	           
	           if(m.find(txt[i]) != m.end()){
	               
	                m[txt[i]]++;
	                
	                if(m[txt[i]] == 1)
	                count++;
	           }

	           
	           //slide the window
	           i++, j++;
	       }
	   }
	   
	   return ans;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
