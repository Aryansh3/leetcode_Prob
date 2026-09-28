class Solution {
public:
    int reverseDegree(string s) {
        int sum =0;
        for(int i=s.length();i>0;i--){
            sum += ('z'-s[i-1] +1)*i;
        //  sum += reversed_num *i
        }
        return sum;
    }
};