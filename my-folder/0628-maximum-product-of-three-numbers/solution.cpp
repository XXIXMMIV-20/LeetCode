class Solution {
public:
    int partition(vector<int> &nums , int low , int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i < j){
            while(nums[i] <= pivot && i <= high - 1) i++;
            while(nums[j] > pivot && j >= low + 1) j--;
            if(i < j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        int temp = nums[low];
        nums[low] = nums[j];
        nums[j] = temp;
        return j;
    }
    void qs(vector<int> &nums , int low , int high){
        if(low < high){
            int pIndex = partition(nums , low , high);
            qs(nums , low , pIndex - 1);
            qs(nums , pIndex + 1 , high);
        }
    }
    int maximumProduct(vector<int>& nums) {
        qs(nums , 0 , nums.size() - 1);
        int option1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        int option2 = nums[0] * nums[1] * nums[nums.size() - 1];
        return max(option1 , option2);
    }
};
