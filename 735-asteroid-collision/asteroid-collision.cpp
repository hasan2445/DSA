class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>v;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty()) st.push(asteroids[i]);
            else
            {
                bool alive=false;
                while(!st.empty() && (asteroids[i]<0 && st.top()>0))
                {
                    if(abs(asteroids[i])==abs(st.top()))
                    {
                        alive=true;
                        st.pop();
                        break;
                    }
                    else if(abs(asteroids[i])<abs(st.top()))
                    {
                        alive=true;
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                if(!alive) st.push(asteroids[i]);
            }
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;

    }
};