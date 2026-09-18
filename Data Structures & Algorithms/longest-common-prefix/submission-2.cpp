class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int minlen=300;
        for(string str:strs){
            minlen=min(minlen,(int)str.length());
        }

        for(int i=1;i<strs.size();i++){
            string temp="";
            for(int j=0;j<minlen;j++){
                if(ans[j]!=strs[i][j]){
                    break;
                }
                temp+=ans[j];
            }
            ans=temp;
        }
        return ans;
    }
};