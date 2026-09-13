class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> num1(nums1.begin(), nums1.end());
        std::unordered_set<int> num2(nums2.begin(), nums2.end());
        vector<int> res;
        int n = num1.size();

        for(int x: num1){
            if(num2.find(x)!=num2.end()){
                res.push_back(x);
            }
        }
        return res;

    }
};