class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans;
        int max_n = *max_element(candies.begin(), candies.end());
        for(int ele: candies){
            if(ele + extraCandies >= max_n){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};