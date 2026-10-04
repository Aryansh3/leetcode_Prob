class Solution {
public:

    bool valid( string s){
        string res ="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                res.push_back('(');
            }else if(s[i]==')'){
                if(res.empty()){
                    return false;
                }
                res.pop_back(); 
            }
        }
        return res.empty();
    }
    bool helper( string s){

        int st = s.find('*');
        if(st == string::npos){
            return valid(s);
        }
        string a=s;
        string b=s;
        string c=s;
        a.replace(st,1,"(");
        b.replace(st,1,"");
        c.replace(st,1,")");
        return helper(a) || helper(b) || helper(c);
    }

    bool checkValidString(string s) {
        return helper(s);
    }
};
