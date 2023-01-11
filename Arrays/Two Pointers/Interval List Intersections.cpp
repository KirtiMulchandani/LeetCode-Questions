class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size(), n2 = secondList.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            vector<int> temp;

            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[j][0], e2 = secondList[j][1];

            if(s2 <= e1 && s1 <= e2){
                int s = max(s1, s2);
                int e = min(e1, e2);
                temp.push_back(s);
                temp.push_back(e);
                ans.push_back(temp);
            }


            if(e1 < e2) 
                i++;
            else   
                j++;
        }
        return ans;
    }
};
