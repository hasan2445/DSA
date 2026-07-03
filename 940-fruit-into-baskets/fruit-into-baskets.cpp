class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>s;
        int i=0;
        int j=0;
        int ans=0;
        int n=fruits.size();
        while(j<n)
        {
            s[fruits[j]]++;
            while(s.size()>=3)
            {
                s[fruits[i]]--;
                if(s[fruits[i]]==0) s.erase(fruits[i]);
                i++;

            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};