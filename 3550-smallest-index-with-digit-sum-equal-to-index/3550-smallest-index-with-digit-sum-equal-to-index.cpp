class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i= 0;i<n;i++){
            if(nums[i]<10){
                if(nums[i] == i){
                    return nums[i];
                }
            }else if(nums[i]>=10 && nums[i]<=1000){
                int sum = 0;
                int dig =nums[i];

                while(dig !=0){
                    int r = dig % 10;
                    dig = dig/10;
                    sum += r;
                }
                if(sum == i){
                    return sum;
                }
            }
        }
        return -1;
    }
};