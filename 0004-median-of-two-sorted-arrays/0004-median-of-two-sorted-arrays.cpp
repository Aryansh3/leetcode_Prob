class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;
        int j=0, k=0;
        vector<int> nums;
        while (j < n1 && k < n2) {
            if (nums1[j] < nums2[k]) {
                nums.push_back(nums1[j]);
                j++;
            } else {
                nums.push_back(nums2[k]);
                k++;
            }
        }
        while (j < n1) {
            nums.push_back(nums1[j]);
            j++;
        }
        while (k < n2) {
            nums.push_back(nums2[k]);
            k++;
        }
        double med =0;
        int m = n/2;
        if(n%2 != 0){
            med = nums[m];
        }else{
            med = (nums[m-1]+nums[m])/2.0;
        }
        return med;
    }
};