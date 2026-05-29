class Solution {
public:
    void reverse(vector<int>& nums , int start , int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums , 0 , nums.size() - 1);
            return;
        }
        for(int i = n-1; i > index; i--){
            if(nums[i] > nums[index]){
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        reverse(nums , index + 1 , nums.size() - 1);
    }
};
