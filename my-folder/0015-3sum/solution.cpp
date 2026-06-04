class Solution {
public:
    void merge(vector<int>& nums , int low , int mid , int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int>& nums , int low , int high){
        if(low == high) return;
        int mid = (low + high) / 2;
        mergeSort(nums , low , mid);
        mergeSort(nums , mid + 1 , high);
        merge(nums , low , mid , high);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        mergeSort(nums , 0 , nums.size() - 1);
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    vector<int> temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
