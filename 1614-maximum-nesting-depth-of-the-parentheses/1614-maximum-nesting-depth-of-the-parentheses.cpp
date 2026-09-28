class Solution {
public:
    int maxDepth(string s) {
        int count=0, h =0;
        for(int i=0; i< s.size(); i++){
            if(s[i]=='('){
                count++;
                h = max(h,count);
            }else if(s[i]==')'){
                count--;
            }
        }
        return h;
    }
};