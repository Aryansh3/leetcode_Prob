class Solution {
public:

    bool valid(string s){
        string s2= "";
        for(int i=0; i<s.size();i++){
            if(s[i]=='('){
                s2.push_back(s[i]);
            }else if(s[i]==')'){
                if(!s2.empty() && s2.back()=='('){
                    s2.pop_back();
                }else{
                    return false;
                }
            }
        }
        return s2.empty();
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;

        while(!q.empty()) {

            string cur = q.front();
            q.pop();

            if(valid(cur)) {
                res.push_back(cur);
                found = true;
            }

            if(found)
                continue;

            for(int i = 0; i < cur.size(); i++) {
                if(cur[i] != '(' && cur[i] != ')')
                    continue;

                string next = cur;
                next.erase(i, 1);

                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return res;
    }
};