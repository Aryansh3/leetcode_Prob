class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> alp_frq(26,0);
        for(int i = 0; i < s.size(); i++){
            alp_frq[s[i] -'a']++;
            alp_frq[t[i] -'a']--;
        }
        for(int x: alp_frq){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
};