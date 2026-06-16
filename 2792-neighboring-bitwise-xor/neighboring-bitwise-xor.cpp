class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int x=0;
        for(int i=0;i<derived.size();i++)
        {
            x=derived[i]^x;

        }
        if(x==0)return true;
        return false;
        }
};