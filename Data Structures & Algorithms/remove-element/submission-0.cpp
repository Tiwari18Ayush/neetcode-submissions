class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        int r=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                l=i;r=i;break;
            }
        }
       
        int n=nums.size();
        while(r<n){
            if(nums[r]!=val){
                swap(nums[l],nums[r]);
                l=l+1;
            }
            r++;
        }
        return l;
    }
};