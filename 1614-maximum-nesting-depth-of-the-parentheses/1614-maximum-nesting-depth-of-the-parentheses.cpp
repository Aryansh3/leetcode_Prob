class Solution {
public:
    int maxDepth(string s) {
        int count=0, h =0;
        for(char x: s){
            if(x =='('){
                count++;
                if(count>h){
                    h = count;
                }
            }else if(x ==')'){
                count--;
            }
        }
        return h;
    }
};