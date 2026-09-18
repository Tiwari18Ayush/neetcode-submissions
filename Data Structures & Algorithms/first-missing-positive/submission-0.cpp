class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums){
            if(i<=0) continue;
            mp[i]=1;
        }
        int last=1;
         for(auto it:mp){
            if(it.first!=last) break;
            last++;
         }
        return last;
    }
};