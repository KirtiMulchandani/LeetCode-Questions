// Iteraive solution

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0, j = 0;

        while(i < s.length() && j < t.length()){
            if(s[i] == t[j])
                i++, j++;
            else
                j++;
        }

        if(i < s.length())
            return false;

        return true;
    }
};


// Recursive Solution

class Solution {
public:
    bool check(string s, string t, int m, int n){
        if(m == 0)
            return true;
        if(n == 0)
            return false;

        if(s[m-1] == t[n-1])
            return check(s, t, m-1, n-1);
        else
            return check(s, t, m, n-1);
    }

    bool isSubsequence(string s, string t) {
        return check(s, t, s.length(), t.length());
    }
};
