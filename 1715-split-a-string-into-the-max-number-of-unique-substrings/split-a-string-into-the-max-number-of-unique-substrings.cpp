#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        int maxSplits = 0;
        backtrack(s, 0, seen, 0, maxSplits);
        return maxSplits;
    }

private:
    void backtrack(const string& s, int start, unordered_set<string>& seen, int currentSplits, int& maxSplits) {
        int n = s.length();
        
        // Pruning: If even splitting every remaining character individually 
        // cannot beat maxSplits, stop searching down this path.
        if (currentSplits + (n - start) <= maxSplits) {
            return;
        }

        // Base case: Reached the end of the string
        if (start == n) {
            maxSplits = max(maxSplits, currentSplits);
            return;
        }

        string sub = "";
        for (int i = start; i < n; ++i) {
            sub += s[i]; // Build substring character by character

            // If the substring has not been used yet
            if (seen.find(sub) == seen.end()) {
                seen.insert(sub); // Choose
                
                // Recurse to find splits for the rest of the string
                backtrack(s, i + 1, seen, currentSplits + 1, maxSplits);
                
                seen.erase(sub); // Backtrack
            }
        }
    }
};
