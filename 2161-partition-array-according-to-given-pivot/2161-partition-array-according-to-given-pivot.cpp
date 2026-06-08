class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int numLess = 0;
        int numEqual = 0;
        vector<int> ans(nums.size());
        for(auto num : nums){
            if(num < pivot) numLess++;
            else if(num == pivot) numEqual++;
        }
        int lessI = 0;
        int EqualI = numLess;
        int GreaterI = numLess + numEqual;
        for(auto num : nums){
            if(num < pivot){
                ans[lessI] = num;
                lessI++;
            }
            else if(num == pivot){
                ans[EqualI] = num;
                EqualI++;
            }
            else{
                ans[GreaterI] = num;
                GreaterI++;
            }
        }
        return ans;
    }
};