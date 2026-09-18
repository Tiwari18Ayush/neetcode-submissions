class Solution {
public:
void merge(int start,int mid,int end,vector<int>&nums){
vector<int>temp;
int i=start;
int j=mid+1;
while(i<=mid&&j<=end){
    if(nums[i]<=nums[j]){
        temp.push_back(nums[i]);
        i++;
    }
    else {
       temp.push_back(nums[j]);
       j++; 
    }
}
while(i<=mid){
    temp.push_back(nums[i]);
        i++;
}
while(j<=end){
    temp.push_back(nums[j]);
       j++;  
}
for(int k=0;k<temp.size();k++){
    nums[start+k]=temp[k];
}
}
void mergesort(int start,int end,vector<int>&nums){
if(end<=start) return;
int mid=start+(end-start)/2;
mergesort(start,mid,nums);
mergesort(mid+1,end,nums);
merge(start,mid,end,nums);
}
    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        mergesort(s,e,nums);
        return nums;
    }
};