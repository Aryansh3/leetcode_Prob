class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int index = abs(a[i]) - 1;
            if(a[index] < 0){
                ans.push_back(abs(a[i]));
            }else{
                a[index] = -a[index];
            }
        }
        return ans;
    }
};