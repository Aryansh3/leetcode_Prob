class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n =0;
        for(int x: nums){
            n ^= x;
        }
        long long bit =  (long long)n & -(long long)n;
        int a =0, b =0;
        for (int x:nums){
            if(x & bit){
                a ^=x;
            }else{
                b^=x;
            }
        }
        return {a,b};
    }
};