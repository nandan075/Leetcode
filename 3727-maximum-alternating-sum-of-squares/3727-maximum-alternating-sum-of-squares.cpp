
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(1LL * nums[i] * nums[i]);
        }

        sort(ans.begin(), ans.end());

        int left = 0;
        int right = ans.size() - 1;
        long long sum = 0;

        while (left <= right) {
            if (left == right) {
                sum += ans[right];
            } else {
                sum += ans[right] - ans[left];
            }

            left++;
            right--;
        }

        return sum;
    }
};
