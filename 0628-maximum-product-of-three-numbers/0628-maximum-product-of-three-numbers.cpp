class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN, smallest= INT_MAX, secondSmallest = INT_MAX;
        int n = nums.size();
        
        if(n<3){
            return -1;
        }
        for(int i = 0; i<n;i++){
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }else if(nums[i]> second){
                third = second;
                second = nums[i];
            }else if(nums[i]> third){
                third = nums[i];
            }

            if (nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            }
            else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }

        
        int num1 =first*smallest*secondSmallest;
        int num2 = first* second*third;
        return max(num1, num2);
    }
};