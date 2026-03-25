class Solution {
public:
    string interpret(string str1) 
    {
        string s;
        for(int i=0;i<str1.size();i++)
	 {
		if(str1[i]=='G')
			s.push_back(str1[i]);
		if(str1[i]=='('&&str1[i+1]==')')
		{
			s.push_back('o');
			i=i+1;
		}
		if(str1[i]=='('&&str1[i+1]=='a'&&str1[i+2]=='l'&&str1[i+3]==')')
		{
			s.push_back('a');
		    s.push_back('l');
		    i=i+3;
		}
	 }
	   
       
       return s;
    }
    
};