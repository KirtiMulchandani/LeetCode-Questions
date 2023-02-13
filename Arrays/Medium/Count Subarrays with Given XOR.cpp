#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> m;
    int xorr = 0, cnt = 0;

    for(int i : arr){
        xorr ^= i;

        if(xorr == x)  //if current xor == x
            cnt++;
        
        if(m.find(xorr ^ x) != m.end()) // check for y = xor ^ x
            cnt += m[xorr^x];

        m[xorr]++;

    }

    return cnt;

}
