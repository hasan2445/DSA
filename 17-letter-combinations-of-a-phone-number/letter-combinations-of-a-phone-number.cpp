class Solution {
public:
    void solve(int i, string digits, string curr, vector<string>& ans, vector<string>& mappings) {
        if(i >= digits.size()) {
            if(!curr.empty()) ans.push_back(curr);
            return;
        }
        
        int digit = digits[i] - '0';
        string letters = mappings[digit];
        
        
        if(digit == 7 || digit == 9) { 
            solve(i + 1, digits, curr + letters[0], ans, mappings);
            solve(i + 1, digits, curr + letters[1], ans, mappings);
            solve(i + 1, digits, curr + letters[2], ans, mappings);
            solve(i + 1, digits, curr + letters[3], ans, mappings);
        }
        else { 
            solve(i + 1, digits, curr + letters[0], ans, mappings);
            solve(i + 1, digits, curr + letters[1], ans, mappings);
            solve(i + 1, digits, curr + letters[2], ans, mappings);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mappings = {
            "", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> ans;
        solve(0, digits, "", ans, mappings);
        return ans;
    }
};