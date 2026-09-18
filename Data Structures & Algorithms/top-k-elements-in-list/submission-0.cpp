class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp1;
        for(int i:nums){
            mp1[i]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp1){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            return(a.first>b.first);
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
