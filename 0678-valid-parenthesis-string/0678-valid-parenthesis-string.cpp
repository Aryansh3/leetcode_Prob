class Solution {
public:
    bool checkValidString(string s) {
        int h = 0, l = 0;
        for(int i= 0;i<s.size(); i++){
            if(s[i]=='('){
                h++;
                l++;
            }else if(s[i] == ')'){
                h--;
                l--;
            }else{
                l--;
                h++;
            }
            if(h<0){
                return false;
            }
            l = max(0,l);
        }
        return l==0;
    }
};