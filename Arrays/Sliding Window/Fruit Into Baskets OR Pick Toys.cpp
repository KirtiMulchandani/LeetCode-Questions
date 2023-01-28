class Solution {
public:
int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> m;

        int i = 0, j = 0;
        int mx = 1;
        while (j < fruits.size())
        {
            m[fruits[j]]++;

            while (m.size() > 2)
            {
                m[fruits[i]]--;

                if (m[fruits[i]] == 0)
                    m.erase(fruits[i]);

                i++;
            }
            if (m.size() <= 2)
                mx=max(mx,j-i+1);

            j++;
            
        }

        return mx;
    }
};
