class Solution { 
public: 
    int minOperations(vector<int>& nums, int x) { 
        int n = nums.size();
        // Calculate the target sum for our sliding window
        long long sum = 0;
        for (int num : nums) sum += num;
        long long target = sum - x; 
        
        // Edge cases
        if (target < 0) return -1;
        if (target == 0) return n;

        int i = 0; 
        long long curr = 0; 
        int max_len = -1; 
        
        for (int j = 0; j < n; j++) { 
            curr += nums[j]; 
            
            // Shrink window from the left if the current sum exceeds target
            while (curr > target && i <= j) { 
                curr -= nums[i]; 
                i++; 
            } 
            
            // Check if we hit the exact target
            if (curr == target) { 
                max_len = max(max_len, j - i + 1); 
            } 
        } 
        
        // If no valid subarray was found, return -1
        return (max_len == -1) ? -1 : (n - max_len); 
    } 
};
