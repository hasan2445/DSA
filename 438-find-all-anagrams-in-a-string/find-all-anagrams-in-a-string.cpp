class Solution { 
public: 
    vector<int> findAnagrams(string s, string p) { 
        unordered_map<int,int> mp; 
        for(int i=0; i<p.size(); i++) { 
            mp[p[i]-'a']++; 
        } 
        int n=s.size(); 
        int i=0, j=0; 
        vector<int> ans; 
        
        while(j < n) { 
            if (mp.count(s[j]-'a')) { 
                mp[s[j]-'a']--; 
                if (mp[s[j]-'a'] == 0) mp.erase(s[j]-'a'); 
                j++; 
            } 
            else { 
                mp[s[i]-'a']++; 
                i++; 
            } 
            
           
            if(mp.size() == 0) {
                ans.push_back(i); 
            }
        } 
        return ans; 
    } 
};
