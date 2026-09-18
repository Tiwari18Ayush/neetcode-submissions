class Solution {
public:
// void mergesort(int start,int end,vector<int>&nums){
// if(end<start) return;
// int mid=start+(end-start)/2;
// mergesort(start,mid,nums);
// mergesort(mid+1,end,nums);
// merge()
// }
    vector<int> sortArray(vector<int>& nums) {
        // int s=0;
        // int e=nums.size()-1;
        // mergesort(s,e,nums)
         vector<int>cnt(1e5+1,0);
         for(int i:nums){
            int idx=i+50000;
            cnt[idx]++;
         }
         int l=0;
         for(int i=0;i<cnt.size();i++){
             while(cnt[i]!=0){
                int val=i-50000;
                nums[l++]=val;
                cnt[i]--;
             }
         }
        return nums;
    }
};