class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int ans=0;
        int r=height.size()-1;
        while(l<r)
        {
            int width=r-l;
            int h=min(height[l],height[r]);
            ans=max(ans,h*width);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return ans;
        
    }
};