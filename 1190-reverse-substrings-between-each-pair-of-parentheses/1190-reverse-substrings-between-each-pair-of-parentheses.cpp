class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string st;        
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                string val="";
                while(st.back()!='('){
                    val += st.back();
                    st.pop_back();
                }
                st.pop_back();
                for(char x: val){
                    st.push_back(x);
                }
            }else{
                st.push_back(s[i]);
            }
        }
        return st;
    }
};