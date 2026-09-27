class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int st=0,end=0;
        for(int i = 0; i < n; i++){
            st=i;
            while(i <n && s[i] !=' '){
                i++;
            }
            end =i-1;
            while(st<end){
                swap(s[st],s[end]);
                st++;
                end--;
            }
        }
        return s;
    }
};