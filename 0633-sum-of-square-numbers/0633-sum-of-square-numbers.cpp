class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        long long j =n, k=0,sum =0;
        while(j >= k){
            sum = k*k + j*j;
            if(sum == c){
                return true;
            }else if(sum > c){
                j--;
            }else{
                k++;
            }
        }
        return false;
    }
};