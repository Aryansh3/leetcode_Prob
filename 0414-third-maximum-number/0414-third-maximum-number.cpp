class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long F = LLONG_MIN, S = LLONG_MIN, T = LLONG_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == F || nums[i] == S || nums[i] == T){
                continue;
            }
            if(nums[i]>F){
                T= S;
                S=F;
                F= nums[i];
            }else if(nums[i]> S){
                T= S;
                S= nums[i];
            }else if(nums[i]> T){
                T = nums[i];
            }
        }

        if(T == LLONG_MIN){
            return F;
        }
        return T;
    }
};