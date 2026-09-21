class Solution {
public:
    string removeStars(string s) {
        stack<char>stack;
        for( char c : s){
            if(c == '*'){
                if(!stack.empty()){
                    stack.pop();
                }
            }else{
                stack.push(c);
            }
        }
        string ans;
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};