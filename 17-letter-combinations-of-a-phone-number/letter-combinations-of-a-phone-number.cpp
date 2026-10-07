class Solution {
public:
    void helper(vector<string>&ans,string curr,int i,vector<string>&map,string digits)
    {
        if(digits.size()==curr.size())
        {
            ans.push_back(curr);
            return;
        }
            int x=digits[i]-'0';
            if(digits[i]!='7'&& digits[i]!='9')
            {
                helper(ans,curr+map[x][0],i+1,map,digits);
                helper(ans,curr+map[x][1],i+1,map,digits);
                helper(ans,curr+map[x][2],i+1,map,digits);
            }
            else
            {
                helper(ans,curr+map[x][0],i+1,map,digits);
                helper(ans,curr+map[x][1],i+1,map,digits);
                helper(ans,curr+map[x][2],i+1,map,digits);
                helper(ans,curr+map[x][3],i+1,map,digits);

            }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>map={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string curr="";
        helper(ans,curr,0,map,digits);
        return ans;
    }
};