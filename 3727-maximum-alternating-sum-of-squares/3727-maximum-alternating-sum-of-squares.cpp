class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        for (int i=0; i<n; i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long res_h = 0, res_l = 0;
        while(j>=i){
            if( i==j){
                res_h = res_h + 1LL*nums[j]*nums[j];
                break;
            }else{ 
                res_h = res_h + 1LL*nums[j]*nums[j];
                j--;
                res_l = res_l + 1LL*nums[i]*nums[i];
                i++;
            }
        }
        return (res_h - res_l);
    }
};