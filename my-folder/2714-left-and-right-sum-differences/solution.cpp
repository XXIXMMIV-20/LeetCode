class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }
        int leftSum = 0 , rightSum = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            rightSum = totalSum - (nums[i] + leftSum);
            ans.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }
        return ans;
    }
};
