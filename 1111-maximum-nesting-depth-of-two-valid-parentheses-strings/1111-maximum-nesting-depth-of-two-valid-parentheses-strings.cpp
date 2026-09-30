class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans;
        int count = -1;
        for(int i=0;i<n; i++){
            if(seq[i]=='('){
                count++;
                ans.push_back(count%2);
                
            }else if(seq[i]==')'){
                ans.push_back(count%2);
                count--;
            }
        }
        return ans;
    }
};