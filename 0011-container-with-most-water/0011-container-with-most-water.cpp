class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxarea = 0;

        while(left < right){

            int area = (right - left) * min(height[left] , height[right]);

            maxarea = max(maxarea , area);

            if(height[left] < height[right]){
                left++;
            }

            else{
                right--;
            }


        }

        return maxarea;
        
    }
};