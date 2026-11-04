
class Solution {
public:
    bool isPal(string &s, int st, int end) {
        while (st < end) {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int st = 0, end = s.size() - 1;
        while (st < end) {
            if (s[st] != s[end]) {
                return isPal(s, st + 1, end) ||
                       isPal(s, st, end - 1);
            }
            st++;
            end--;
        }

        return true;
    }
};
