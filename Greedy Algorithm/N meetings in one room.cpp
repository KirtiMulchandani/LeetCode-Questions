//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool static cmp(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int ans = 1, curr = v[0].second;
        
        for(int i = 0; i < n-1; i++){
            if(curr < v[i+1].first){
                ans++;
                curr = v[i+1].second;
            }
            else{
                if(v[i+1].second < curr) curr = v[i+1].second;
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
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
