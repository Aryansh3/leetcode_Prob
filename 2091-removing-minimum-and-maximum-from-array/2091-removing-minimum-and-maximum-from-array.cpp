class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxidx=0,minidx=0;
        for(int i =0; i<n;i++){
            if(nums[i] > nums[maxidx]){
                maxidx =i;
            }
            if(nums[i] < nums[minidx]){
                minidx =i;
            }   
        }
        int front = max(maxidx,minidx)+1;
        int back = n - min(maxidx, minidx);
        int both =  (min(maxidx,minidx)+1) +( n - max(maxidx, minidx));

        return min({front,back,both});
    }
};