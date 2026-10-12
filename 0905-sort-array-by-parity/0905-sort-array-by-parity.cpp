class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            if(nums[right] % 2 == 1 ){
                  
                  right--;
            }

            else if(nums[left] % 2 == 0){
                left++;
            }

            else{
                swap(nums[left] , nums[right]);

                left++;
                right--;
            }
        }
        return nums;
    }
};