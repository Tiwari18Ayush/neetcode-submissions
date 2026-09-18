class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for (string it : strs) {
            s += it;
            s += "#PI*";
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int start = 0;

        while (start < s.size()) {
            int pos = s.find("#PI*", start);

            ans.push_back(s.substr(start, pos - start));

            start = pos + 4;
        }

        return ans;
    }
};