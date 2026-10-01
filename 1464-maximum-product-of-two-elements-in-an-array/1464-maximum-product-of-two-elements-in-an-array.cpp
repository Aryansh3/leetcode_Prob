class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int fm =0,sm =0;
        for(int i=0; i<n; i++){
            if(fm < nums[i]){
                sm = fm;
                fm = nums[i];
            }else if(sm < nums[i]){
                sm = nums[i];
            }
        }
        return ((fm-1)*(sm-1));
    }
};