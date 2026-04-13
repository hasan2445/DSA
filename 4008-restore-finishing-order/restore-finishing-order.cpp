class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int>mp;
        for(int i=0;i<friends.size();i++){
            mp[friends[i]]++;
        }
        vector<int>ans;

        for(int i=0;i<order.size();i++){
            if(mp[order[i]])ans.push_back(order[i]);
            else{
                continue;
            }

        }
        return ans;
        
    }
};