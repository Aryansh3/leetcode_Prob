class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int st =0;
        int res = 0;
        for(int end =0; end<s.size(); end++){
            while(m.find(s[end]) != m.end()){
                m.erase(s[st]);
                st++;
            }
            m.insert(s[end]);
            res = max(res, end-st+1);
        }
        return res;
    
    }
};