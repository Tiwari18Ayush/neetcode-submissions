class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        if(nums.size()==1) return 1;
        int l=0;
        int r=1;
        int n=nums.size();
        int maxi=1;
        int len=1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==1+nums[i]){
                maxi=max(maxi,1+len);
                len++;
            }
            else len=1;
        }
        return maxi;
    }
};
