class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }
        string ans = "";
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i]=='(' ){
                string str ="";
                i++;
                while(s[i] != ')'){
                    str += s[i];
                    i++;
                }
                if(mp.find(str)!= mp.end()){
                    ans+=mp[str];
                }else{
                    ans+="?";
                }
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};