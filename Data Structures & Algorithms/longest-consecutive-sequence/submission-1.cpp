class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        unordered_map<int,int>mp;
        mp[nums[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            int nextval=nums[i]+1;
            if(mp.find(nextval)!=mp.end()){
                dp[i]+=mp[nextval];
            }
            mp[nums[i]]=dp[i];
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};