class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
       for(int i=0;i<tokens.size();i++)
       {
        if(tokens[i]=="+"||tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="-")
        {
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(tokens[i]=="+")
            {
                int sum=a+b;
                st.push(sum);
            }
            else if(tokens[i]=="-")
            {
                int sum=a-b;
                st.push(sum);
            }
            else if(tokens[i]=="*")
            {
                int sum=a*b;
                st.push(sum);
            }
            else 
            {
                st.push(a/b);
            }
        }
        else
        {
            int x=stoi(tokens[i]);
            st.push(x);
        }
       } 
       return st.top();
    }
};