class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int t) {
        vector<vector<int>>v(boxTypes.size());
        for(int i=0;i<boxTypes.size();i++)
        {
            v[i].push_back(boxTypes[i][1]);
             v[i].push_back(boxTypes[i][0]);
        }
        sort(v.begin(),v.end());
        int sum=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(t>0)
            {
                if(t>=v[i][1])
                {
                    sum+=v[i][0]*v[i][1];
                    t-=v[i][1];
                }
                else
                {

                    sum+=t*v[i][0];
                    return sum;
                    
                }
            }
            else return sum;
        }
        return sum;
    }
};