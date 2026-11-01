class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int min = *min_element(nums.begin(), nums.end());
        for(int x:nums){
            sum += x;
        }
        return sum - nums.size() * min;
    }
};