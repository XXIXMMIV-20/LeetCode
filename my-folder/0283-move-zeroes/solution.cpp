class Solution {
public:
    void swap(vector<int> &nums , int start , int end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums , i , j);
                i++;
            }
        }
    }
};
