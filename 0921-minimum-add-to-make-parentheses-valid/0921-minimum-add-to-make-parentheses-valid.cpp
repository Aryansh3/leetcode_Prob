class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int h = 0,l=0;
        string st="";
        for(int i =0; i<n; i++){
            if(s[i]=='('){
                st.push_back(s[i]);
                h++;
            }else if(s[i]==')'&& !st.empty() && st.back()=='('){
                h--;
                st.pop_back();
            }else if(s[i]==')'){
                l++;
            }
        }
        return h+l;
    }
};