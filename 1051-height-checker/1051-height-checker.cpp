class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> old_h = heights;
        int count=0;
        sort(heights.begin(), heights.end());
        for(int i=0; i<heights.size();i++){
            if(heights[i] != old_h[i]){
                count++;
            }
        }
        return count;
    }
};